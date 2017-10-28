//
//  Texture2D.cpp
//  EXPGL
//
//  Created by Nick Fagan on 10/22/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#include "Texture2D.hpp"

EXP::Texture2D::Texture2D(unsigned id, int width, int height) : EXP::Texture(id)
{
    this->width = width;
    this->height = height;
}

EXP::Texture2D::~Texture2D() {}

void EXP::Texture2D::Activate(unsigned offset)
{
    glActiveTexture(GL_TEXTURE0 + offset);
    glBindTexture(GL_TEXTURE_2D, id);
}

int EXP::Texture2D::GetWidth() const
{
    return width;
}

int EXP::Texture2D::GetHeight() const
{
    return height;
}
