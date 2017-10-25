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
#include "Texture.hpp"

namespace EXP {
    class Model
    {
    public:
        enum UNITS {
            NORMALIZED,
            PIXELS,
            MIXED
        };
        
        unsigned ID;
        
        Model(EXP::Mesh *mesh);
        Model(EXP::Mesh *mesh, EXP::Texture *texture);
        
        virtual ~Model();
        
        void SetID(unsigned id);
        virtual void SetPosition(glm::vec3 position);
        virtual void SetRotation(glm::vec3 rotation);
        virtual void SetUnits(UNITS units);
        
        virtual glm::mat4 GetTransformationMatrix() const;
        virtual void Draw(void);
    protected:
        bool is_textured;
        EXP::Mesh *mesh;
        EXP::Texture *texture;
        glm::vec3 position;
        glm::vec3 rotation;
        UNITS units = NORMALIZED;
    };
}

#endif /* Model_hpp */
