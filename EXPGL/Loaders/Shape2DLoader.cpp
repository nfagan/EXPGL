//
//  Shape2DLoader.cpp
//  EXPGL
//
//  Created by Nick Fagan on 10/22/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#include "Shape2DLoader.hpp"

EXP::Shape2DLoader::Shape2DLoader(EXP::TextureLoader *texture_loader)
{
    this->texture_loader = texture_loader;
}

EXP::Shape2DLoader::~Shape2DLoader()
{
    for (unsigned i = 0; i < shapes.size(); ++i)
    {
        delete shapes[i];
    }
}

EXP::Rectangle* EXP::Shape2DLoader::CreateRectangle()
{
    EXP::Rectangle *rectangle = new EXP::Rectangle();
    shapes.push_back(rectangle);
    return rectangle;
}
