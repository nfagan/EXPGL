//
//  Model.hpp
//  EXPGL
//
//  Created by Nick Fagan on 10/22/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#ifndef Model_hpp
#define Model_hpp

#include <stdio.h>
#include <atomic>
#include "../Mesh/Mesh.hpp"
#include "../Material/Material.hpp"
#include "../Texture/Texture.hpp"
#include "../Render/Shader.hpp"
#include "../Resource/GLResourcePrimitive.hpp"

namespace EXP {
    class Model : public GLResourcePrimitive
    {
        
        friend class ModelLoader;
    public:
        enum UNITS {
            NORMALIZED,
            PIXELS,
            MIXED
        };
    
        Model(EXP::Mesh *mesh, EXP::Material *material);
        virtual ~Model() = default;
        
        virtual void SetShader(EXP::Shader *shader);
        virtual void SetMaterial(EXP::Material *material);
        virtual void SetMesh(EXP::Mesh *mesh);
        virtual void SetPosition(glm::vec3 position);
        virtual void SetPosition(glm::vec2 position);
        virtual void SetRotation(glm::vec3 rotation);
        virtual void SetRotation(glm::vec2 rotation);
        virtual void SetScale(glm::vec3 scale);
        virtual void SetScale(glm::vec2 scale);
        virtual void SetScale(float scale);
        virtual void SetUnits(UNITS units);
        
        virtual void Initialize(EXP::RenderTarget *target);
        virtual void MakeLike(EXP::Model *model);

        virtual bool Is2D(void) const;
        
        virtual glm::vec3 GetPosition(void) const;
        virtual glm::vec3 GetScale(void) const;
        virtual glm::vec3 GetRotation(void) const;
        virtual UNITS GetUnits(void) const;
        virtual EXP::Shader* GetShader(void) const;
        virtual EXP::Material* GetMaterial(void) const;
        
        virtual glm::mat4 GetTransformationMatrix(Rect<float> screen) const;
        virtual void Draw(unsigned index);
    protected:
        bool is_2d;
        std::atomic<EXP::Shader*> shader;
        std::atomic<EXP::Mesh*> mesh;
        std::atomic<EXP::Material*> material;
        glm::vec3 position;
        glm::vec3 rotation;
        glm::vec3 scale;
        UNITS units = NORMALIZED;
        
        void initialize_mesh(EXP::RenderTarget *target);
        glm::vec3 get_units_position(const Rect<float> &screen) const;
        glm::vec3 get_units_scale(const Rect<float> &screen) const;
        glm::mat4 get_transformation_matrix(const Rect<float> &screen) const;
    };
}

#endif /* Model_hpp */
