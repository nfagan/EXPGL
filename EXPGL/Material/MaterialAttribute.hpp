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
        friend class Material;
    public:
        MaterialAttribute(void)
        {
            Set(0.0f);
        }
        MaterialAttribute(glm::vec3 data)
        {
            Set(data);
        }
        MaterialAttribute(Texture *data)
        {
            Set(data);
        }
        MaterialAttribute(float data)
        {
            Set(data);
        }
        MaterialAttribute(const MaterialAttribute &data) {
            copy_from(data);
        }
        
        MaterialAttribute& operator=(const MaterialAttribute& other)
        {
            if (&other == this) return *this;
            copy_from(other);
            return *this;
        }
        
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
            name_lock.lock();
            switch (attribute.tag)
            {
                case Attribute::VEC3:
                    shader->SetBool((name + "_use_texture").c_str(), false);
                    shader->SetVec3((name + "_value_vec3").c_str(), attribute.data.vec3_value);
                    break;
                case Attribute::TEXTURE:
                    shader->SetBool((name + "_use_texture").c_str(), true);
                    shader->SetInt((name + "_value_sampler2d").c_str(), attribute.data.tex_value->GetIndex());
                    break;
                case Attribute::FLOAT:
					shader->SetBool((name + "_use_texture").c_str(), false);
                    shader->SetFloat((name + "_value_float").c_str(), attribute.data.float_value);
                    break;
                default:
                    assert(false);
            }
            data_lock.unlock();
            name_lock.unlock();
        };
    protected:
        std::string name;
        spinlock name_lock;
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
        
        void set_name(std::string name)
        {
            name_lock.lock();
            this->name = name;
            name_lock.unlock();
        }
        
        void copy_from(const MaterialAttribute &other)
        {
            switch (other.attribute.tag)
            {
                case Attribute::VEC3:
                    Set(other.attribute.data.vec3_value);
                    break;
                case Attribute::TEXTURE:
                    Set(other.attribute.data.tex_value);
                    break;
                case Attribute::FLOAT:
                    Set(other.attribute.data.float_value);
                    break;
                default:
                    assert(false);
            }
            set_name(other.name);
        }
    };
}

#endif /* MaterialAttribute_hpp */
