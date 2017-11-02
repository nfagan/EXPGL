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
#include "../Mesh/Mesh.hpp"
#include "../Material/Material.hpp"
#include "../Texture/Texture.hpp"
#include "../Render/Shader.hpp"

namespace EXP {
    class Model
    {
        
        friend class ModelLoader;
    public:
        enum UNITS {
            NORMALIZED,
            PIXELS,
            MIXED
        };
    
        Model(EXP::Mesh *mesh, EXP::Material *material);
        virtual ~Model();
        
        virtual void SetMaterial(EXP::Material *material);
        virtual void SetPosition(glm::vec3 position);
        virtual void SetRotation(glm::vec3 rotation);
        virtual void SetScale(glm::vec3 scale);
        virtual void SetScale(float scale);
        virtual void SetUnits(UNITS units);
        virtual void InitializeMesh(EXP::RenderTarget *target);

        virtual glm::mat4 GetTransformationMatrix() const;
        virtual unsigned GetId() const;
        virtual void Draw(EXP::Shader *shader, unsigned index);
    protected:
        unsigned id;
        EXP::Mesh *mesh;
        EXP::Material *material;
        glm::vec3 position;
        glm::vec3 rotation;
        glm::vec3 scale;
        UNITS units = NORMALIZED;
        
        void set_id(unsigned id);
    };
}

#endif /* Model_hpp */
