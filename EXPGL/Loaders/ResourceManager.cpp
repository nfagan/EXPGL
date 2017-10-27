//
//  ResourceManager.cpp
//  EXPGL
//
//  Created by Nick Fagan on 10/22/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#include "ResourceManager.hpp"

EXP::ResourceManager::ResourceManager()
{
    texture_loader = new TextureLoader();
    model_loader = new ModelLoader(texture_loader);
    material_loader = new MaterialLoader(texture_loader);
}

EXP::ResourceManager::~ResourceManager()
{
    delete texture_loader;
    delete model_loader;
    delete material_loader;
}

EXP::Texture2D* EXP::ResourceManager::GetTexture2D(const char* filename)
{
    return texture_loader->GetTexture2D(filename);
}
