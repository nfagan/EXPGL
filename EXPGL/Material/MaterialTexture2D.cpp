//
//  MaterialTexture2D.cpp
//  EXPGL
//
//  Created by Nick Fagan on 10/26/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#include "MaterialTexture2D.hpp"

EXP::MaterialTexture2D::MaterialTexture2D(EXP::Texture2D *texture)
{
    this->texture = texture;
}

EXP::MaterialTexture2D::~MaterialTexture2D() {};

void EXP::MaterialTexture2D::Configure(EXP::Shader *shader)
{
    texture->Activate(0);
    shader->SetBool("is_textured", true);
    shader->SetInt("image", 0);
}

int EXP::MaterialTexture2D::GetWidth() const
{
    return texture->GetWidth();
}

int EXP::MaterialTexture2D::GetHeight() const
{
    return texture->GetHeight();
}


