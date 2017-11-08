//
//  MaterialTexture2D.cpp
//  EXPGL
//
//  Created by Nick Fagan on 10/26/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#include "MaterialTexture2D.hpp"
#include "../Util/EXPGL_ASSERT.hpp"

EXP::MaterialTexture2D::MaterialTexture2D(EXP::Texture2D *texture)
{
    EXPGL_ASSERT(texture, "Attempted to assign a nullptr texture.");
    this->texture.store(texture);
}

EXP::MaterialTexture2D::~MaterialTexture2D() {};

void EXP::MaterialTexture2D::Configure(EXP::Shader *shader)
{
    texture.load()->Activate(0);
    shader->SetBool("is_textured", true);
    shader->SetInt("image", 0);
}

int EXP::MaterialTexture2D::GetWidth() const
{
    return texture.load()->GetWidth();
}

int EXP::MaterialTexture2D::GetHeight() const
{
    return texture.load()->GetHeight();
}


