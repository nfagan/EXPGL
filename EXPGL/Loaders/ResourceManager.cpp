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
    shape_2d_loader = new Shape2DLoader(texture_loader);
}

EXP::ResourceManager::~ResourceManager()
{
    delete texture_loader;
    delete shape_2d_loader;
}

EXP::Texture2D* EXP::ResourceManager::GetTexture2D(const char* filename)
{
    return texture_loader->GetTexture2D(filename);
}

EXP::Rectangle* EXP::ResourceManager::CreateRectangle()
{
    return shape_2d_loader->CreateRectangle();
}
