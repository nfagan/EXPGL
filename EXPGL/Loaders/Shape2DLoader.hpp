//
//  Shape2DLoader.hpp
//  EXPGL
//
//  Created by Nick Fagan on 10/22/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#ifndef Shape2DLoader_hpp
#define Shape2DLoader_hpp

#include <stdio.h>
#include <unordered_map>
#include "TextureLoader.hpp"
#include "../Model/Shape2D.hpp"
#include "../Model/Rectangle.hpp"

namespace EXP {
    class Shape2DLoader
    {
    public:
        Shape2DLoader(TextureLoader *texture_loader);
        ~Shape2DLoader();
        
        Rectangle* CreateRectangle();
    private:
        TextureLoader *texture_loader;
        std::vector<Shape2D*> shapes;
    };
}

#endif /* Shape2DLoader_hpp */
