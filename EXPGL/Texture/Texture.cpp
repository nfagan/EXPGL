//
//  Texture.cpp
//  EXPGL
//
//  Created by Nick Fagan on 10/22/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#include "Texture.hpp"

EXP::Texture::Texture(unsigned id)
{
    this->id = id;
}

EXP::Texture::~Texture()
{
    glDeleteTextures(1, &id);
}

void EXP::Texture::Activate(unsigned int offset)
{
    glActiveTexture(GL_TEXTURE0 + offset);
}
