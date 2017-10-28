//
//  Image.hpp
//  EXPGL
//
//  Created by Nick Fagan on 10/27/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#ifndef Image_hpp
#define Image_hpp

#include <stdio.h>
#include "Rectangle.hpp"
#include "../Material/MaterialTexture2D.hpp"

namespace EXP {
    class Image : public EXP::Rectangle
    {
    public:
        Image(EXP::MaterialTexture2D *material);
        ~Image();
    };
}

#endif /* Image_hpp */
