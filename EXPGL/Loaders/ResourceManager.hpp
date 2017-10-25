//
//  ResourceManager.hpp
//  EXPGL
//
//  Created by Nick Fagan on 10/22/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#ifndef ResourceManager_hpp
#define ResourceManager_hpp

#include <stdio.h>
#include "TextureLoader.hpp"
#include "Shape2DLoader.hpp"

namespace EXP {
    class ResourceManager
    {
    public:
        ResourceManager();
        ~ResourceManager();
        
        Texture2D* GetTexture2D(const char* filename);
        Rectangle* CreateRectangle();
    private:
        TextureLoader *texture_loader;
        Shape2DLoader *shape_2d_loader;
        
    };
}

#endif /* ResourceManager_hpp */
