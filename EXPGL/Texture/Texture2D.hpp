//
//  Texture2D.hpp
//  EXPGL
//
//  Created by Nick Fagan on 10/22/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#ifndef Texture2D_hpp
#define Texture2D_hpp

#include <stdio.h>
#include "Texture.hpp"

namespace EXP {
    class Texture2D : public Texture
    {
    public:
        Texture2D(unsigned id, int width, int height);
        ~Texture2D();
    private:
        int width;
        int height;
    };
}

#endif /* Texture2D_hpp */
