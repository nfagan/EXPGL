//
//  Shape2DLoader.cpp
//  EXPGL
//
//  Created by Nick Fagan on 10/22/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#include "ModelLoader.hpp"

EXP::ModelLoader::ModelLoader(EXP::TextureLoader *texture_loader)
{
    this->texture_loader = texture_loader;
}

EXP::ModelLoader::~ModelLoader()
{
    for (unsigned i = 0; i < models.size(); ++i)
    {
        delete models[i];
    }
}

EXP::Rectangle* EXP::ModelLoader::CreateRectangle()
{
    EXP::Rectangle *rectangle = new EXP::Rectangle();
    models.push_back(rectangle);
    return rectangle;
}
