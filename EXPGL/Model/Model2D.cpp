//
//  Model2D.cpp
//  EXPGL
//
//  Created by Nick Fagan on 10/22/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#include "Model2D.hpp"

EXP::Model2D::Model2D(EXP::Mesh *mesh, EXP::Material *material) : EXP::Model(mesh, material) {}

EXP::Model2D::~Model2D() {}

void EXP::Model2D::SetPosition(glm::vec2 position)
{
    this->position.x = position.x;
    this->position.y = position.y;
}

void EXP::Model2D::SetRotation(glm::vec2 position)
{
    this->rotation.x = rotation.x;
    this->rotation.y = rotation.y;
}

glm::vec2 EXP::Model2D::GetRotation(void)
{
    return glm::vec2(rotation.x, rotation.y);
}

glm::vec2 EXP::Model2D::GetPosition(void)
{
    return glm::vec2(position.x, position.y);
}

glm::mat4 EXP::Model2D::GetTransformationMatrix(Rect<float> window, Rect<float> screen) const
{
    return Model::GetTransformationMatrix();
}
