//
//  Image.cpp
//  EXPGL
//
//  Created by Nick Fagan on 10/27/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#include "Image.hpp"

EXP::Image::Image(EXP::MaterialTexture2D *material) : EXP::Rectangle(material)
{
    float aspect = (float)material->GetWidth() / (float)material->GetHeight();
    SetDimensions(aspect, 1.0f);
}

EXP::Image::~Image() {};
