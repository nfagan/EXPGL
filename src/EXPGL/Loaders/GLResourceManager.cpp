//
//  ResourceManager.cpp
//  EXPGL
//
//  Created by Nick Fagan on 10/22/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#include <EXPGL/Loaders/GLResourceManager.hpp>

EXP::GLResourceManager::GLResourceManager()
{
    texture_loader = new TextureLoader();
    n_items = 0;
}

EXP::GLResourceManager::~GLResourceManager()
{
    delete texture_loader;
    
    for (unsigned i = 0; i < items.size(); ++i)
    {
        delete items[i];
    }
}
