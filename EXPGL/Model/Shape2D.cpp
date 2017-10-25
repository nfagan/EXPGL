//
//  Shape2D.cpp
//  EXPGL
//
//  Created by Nick Fagan on 10/22/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#include "Shape2D.hpp"

EXP::Shape2D::Shape2D(EXP::Mesh *mesh) : EXP::Model(mesh) {}

EXP::Shape2D::Shape2D(EXP::Mesh *mesh, EXP::Texture2D *texture) : EXP::Model(mesh, texture) {}

EXP::Shape2D::~Shape2D() {}

void EXP::Shape2D::SetPosition(glm::vec2 position)
{
    this->position.x = position.x;
    this->position.y = position.y;
}

void EXP::Shape2D::SetRotation(glm::vec2 position)
{
    this->rotation.x = rotation.x;
    this->rotation.y = rotation.y;
}

glm::vec2 EXP::Shape2D::GetRotation(void)
{
    return glm::vec2(rotation.x, rotation.y);
}

glm::vec2 EXP::Shape2D::GetPosition(void)
{
    return glm::vec2(position.x, position.y);
}

glm::mat4 EXP::Shape2D::GetTransformationMatrix(Rect<float> window, Rect<float> screen) const
{
    return Model::GetTransformationMatrix();
}
