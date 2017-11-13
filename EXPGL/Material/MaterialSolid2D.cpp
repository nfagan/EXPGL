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
	albedo = EXP::Colors::RED;
}

void EXP::MaterialSolid2D::SetAlbedo(glm::vec3 albedo)
{
	albedo_lock.lock();
	this->albedo = albedo;
	albedo_lock.unlock();
}

glm::vec3 EXP::MaterialSolid2D::GetAlbedo()
{
	albedo_lock.lock();
	glm::vec3 albedo_copy = this->albedo;
	albedo_lock.unlock();
	return albedo_copy;
}

void EXP::MaterialSolid2D::Configure(EXP::Shader *shader)
{
    shader->SetBool("is_textured", false);
    shader->SetVec3("albedo", GetAlbedo());
}
