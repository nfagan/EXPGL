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
#include "Model.hpp"
#include "../Mesh/Quad.hpp"
#include "../Util/Rect.hpp"
#include "../Material/MaterialSolid2D.hpp"

namespace EXP {
    class Rectangle : public EXP::Model
    {
    public:
        Rectangle(void);
        Rectangle(EXP::Material *material);
        ~Rectangle();
        
        EXP::Rect<float> GetPixelVertices(EXP::Rect<int> screen) const;
        EXP::Rect<float> GetPixelVertices(EXP::Rect<float> screen) const;
    private:
        bool owns_material;
        EXP::Rect<float> get_pixel_vertices(EXP::Rect<float> screen) const;
    };
}

#endif /* Rectangle_hpp */
