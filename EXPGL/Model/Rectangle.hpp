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
        
        float GetWidth(void) const;
        float GetHeight(void) const;
        
        virtual void MakeLike(EXP::Rectangle *rectangle);
        
        glm::mat4 GetTransformationMatrix(Rect<float> screen) const;
        EXP::Rect<float> GetPixelVertices(EXP::Rect<int> screen) const;
        EXP::Rect<float> GetPixelVertices(EXP::Rect<float> screen) const;
    private:
        bool owns_material;
        float width;
        float height;
        glm::vec3 get_units_scale(Rect<float> screen) const;
        glm::vec3 get_units_position(Rect<float> screen) const;
        glm::mat4 get_transformation_matrix(Rect<float> screen) const;
        EXP::Rect<float> get_pixel_vertices(EXP::Rect<float> screen) const;
    };
}

#endif /* Rectangle_hpp */
