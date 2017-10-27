//
//  Shape2D.hpp
//  EXPGL
//
//  Created by Nick Fagan on 10/22/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#ifndef Shape2D_hpp
#define Shape2D_hpp

#include <stdio.h>
#include "Model.hpp"
#include "Texture2D.hpp"
#include "../Util/Rect.hpp"

namespace EXP {
    class Shape2D : public EXP::Model
    {
    public:
        Shape2D(EXP::Mesh *mesh);
        Shape2D(EXP::Mesh *mesh, EXP::Texture2D *texture);
        virtual ~Shape2D();
        virtual glm::mat4 GetTransformationMatrix(Rect<float> window, Rect<float> screen) const;
        
        virtual void SetPosition(glm::vec2 position);
        virtual void SetRotation(glm::vec2 position);
        
        virtual glm::vec2 GetPosition(void);
        virtual glm::vec2 GetRotation(void);
    };
}

#endif /* Shape2D_hpp */
