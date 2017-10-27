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
#include "MaterialLoader.hpp"

namespace EXP {
    class ResourceManager
    {
    public:
        ResourceManager(void);
        ~ResourceManager(void);
        
        Texture2D* GetTexture2D(const char* filename);
        
        template<typename T>
        T* CreateModel(EXP::RenderTarget *target)
        {
            return model_loader->CreateModel<T>(target);
        };
        
        template<typename T, typename... A>
        T* CreateMaterial(A... args)
        {
            return material_loader->CreateMaterial<T>(args...);
        };
    private:
        TextureLoader *texture_loader;
        ModelLoader *model_loader;
        MaterialLoader *material_loader;
    };
}

#endif /* ResourceManager_hpp */
