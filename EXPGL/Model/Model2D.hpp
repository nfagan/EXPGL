//
//  Model2D.hpp
//  EXPGL
//
//  Created by Nick Fagan on 10/22/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#ifndef Model2D_hpp
#define Model2D_hpp

#include <stdio.h>
#include "Model.hpp"
#include "../Material/Material.hpp"
#include "../Util/Rect.hpp"

namespace EXP {
    class Model2D : public EXP::Model
    {
    public:
        Model2D(EXP::Mesh *mesh, EXP::Material *material);
        virtual ~Model2D();
        virtual glm::mat4 GetTransformationMatrix(Rect<float> screen) const;
        
        virtual void SetPosition(glm::vec2 position);
        virtual void SetRotation(glm::vec2 position);
        
        virtual glm::vec2 GetPosition(void);
        virtual glm::vec2 GetRotation(void);
    };
}

#endif /* Model2D_hpp */
