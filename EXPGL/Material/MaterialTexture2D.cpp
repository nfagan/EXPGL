//
//  MaterialTexture2D.cpp
//  EXPGL
//
//  Created by Nick Fagan on 10/26/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#include "MaterialTexture2D.hpp"
#include "../Util/EXPGL_ASSERT.hpp"

EXP::MaterialTexture2D::MaterialTexture2D(EXP::Texture *texture)
{
    EXPGL_ASSERT(texture, "Attempted to assign a nullptr texture.");
    this->texture.store(texture);
}

void EXP::MaterialTexture2D::Configure(EXP::Shader *shader)
{
    Texture *tex = texture.load();
    tex->Activate();
    shader->SetBool("is_textured", true);
    shader->SetInt("TEX_2D_0", tex->GetIndex());
}

int EXP::MaterialTexture2D::GetWidth() const
{
    return texture.load()->GetWidth();
}

int EXP::MaterialTexture2D::GetHeight() const
{
    return texture.load()->GetHeight();
}


