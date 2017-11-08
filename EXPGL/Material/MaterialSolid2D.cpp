//
//  MaterialSolid2D.cpp
//  EXPGL
//
//  Created by Nick Fagan on 10/26/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#include "MaterialSolid2D.hpp"
#include "../Util/Colors.hpp"

EXP::MaterialSolid2D::MaterialSolid2D() : EXP::Material()
{
    albedo.store(EXP::Colors::RED);
}

void EXP::MaterialSolid2D::SetAlbedo(glm::vec3 albedo)
{
    this->albedo.store(albedo);
}

EXP::MaterialSolid2D::~MaterialSolid2D() {}

void EXP::MaterialSolid2D::Configure(EXP::Shader *shader)
{
    shader->SetBool("is_textured", false);
    shader->SetVec3("albedo", albedo.load());
}
