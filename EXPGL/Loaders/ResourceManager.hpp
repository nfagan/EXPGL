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
#include "ModelLoader.hpp"

namespace EXP {
    class ResourceManager
    {
    public:
        ResourceManager();
        ~ResourceManager();
        
        Texture2D* GetTexture2D(const char* filename);
        Rectangle* CreateRectangle(EXP::RenderTarget *target);
    private:
        TextureLoader *texture_loader;
        ModelLoader *model_loader;
        
    };
}

#endif /* ResourceManager_hpp */
