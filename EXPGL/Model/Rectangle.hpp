//
//  Rectangle.hpp
//  EXPGL
//
//  Created by Nick Fagan on 10/22/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#ifndef Rectangle_hpp
#define Rectangle_hpp

#include <stdio.h>
#include "Model2D.hpp"
#include "../Mesh/Quad.hpp"
#include "../Util/Rect.hpp"
#include "../Material/MaterialSolid2D.hpp"

namespace EXP {
    class Rectangle : public EXP::Model2D
    {
    public:
        Rectangle(void);
        Rectangle(EXP::Material *material);
        ~Rectangle();
        
        void SetDimensions(float width, float height);
        
        glm::mat4 GetTransformationMatrix(Rect<float> window, Rect<float> screen) const;
    private:
        float width;
        float height;
        glm::vec3 get_units_scale(Rect<float> screen) const;
        glm::vec3 get_units_position(Rect<float> screen) const;
        glm::mat4 get_transformation_matrix(Rect<float> window, Rect<float> screen) const;
    };
}

#endif /* Rectangle_hpp */
