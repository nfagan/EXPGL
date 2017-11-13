//
//  MaterialAttribute.hpp
//  EXPGL
//
//  Created by Nick Fagan on 11/12/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#ifndef MaterialAttribute_hpp
#define MaterialAttribute_hpp

#include "../Resource/GLResourcePrimitive.hpp"
#include "../Texture/Texture.hpp"
#include "../Render/Shader.hpp"
#include <EXPUtil/thread/spinlock.hpp>
#include <glm/glm.hpp>

namespace EXP {
    class MaterialAttribute : public GLResourcePrimitive
    {
    public:
        MaterialAttribute() = default;
        MaterialAttribute(glm::vec3 data) { Set(data); }
        MaterialAttribute(Texture *data) { Set(data); }
        MaterialAttribute(float data) { Set(data); }
        ~MaterialAttribute() = default;
        
        void Set(glm::vec3 data)
        {
            data_lock.lock();
            attribute.tag = Attribute::VEC3;
            attribute.data.vec3_value = data;
            data_lock.unlock();
        }
        void Set(Texture *data)
        {
            data_lock.lock();
            attribute.tag = Attribute::TEXTURE;
            attribute.data.tex_value = data;
            data_lock.unlock();
        }
        void Set(float data)
        {
            data_lock.lock();
            attribute.tag = Attribute::FLOAT;
            attribute.data.float_value = data;
            data_lock.unlock();
        }
        
        void Configure(Shader *shader)
        {
            data_lock.lock();
            switch (attribute.tag)
            {
                case Attribute::VEC3:
                    shader->SetVec3((name + "value_vec3").c_str(), attribute.data.vec3_value);
                    break;
                case Attribute::TEXTURE:
                    shader->SetInt((name + "value_sampler2d").c_str(), attribute.data.tex_value->GetIndex());
                    break;
                case Attribute::FLOAT:
                    shader->SetFloat((name + "value_float").c_str(), attribute.data.float_value);
                    break;
                default:
                    assert(false);
            }
            data_lock.unlock();
        };
    protected:
        std::string name;
        struct Attribute {
            enum { VEC3, TEXTURE, FLOAT } tag = VEC3;
            union Data {
                glm::vec3 vec3_value;
                Texture *tex_value;
                float float_value;
                Data() { vec3_value = glm::vec3(1.0f); }
            } data;
        } attribute;
        spinlock data_lock;
    };
}

#endif /* MaterialAttribute_hpp */
