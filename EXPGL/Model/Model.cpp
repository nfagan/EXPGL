//
//  Model.cpp
//  EXPGL
//
//  Created by Nick Fagan on 10/22/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#include "Model.hpp"

EXP::Model::Model(Mesh *mesh)
{
    this->mesh = mesh;
	this->position = glm::vec3(0.0f);
    is_textured = false;
}

EXP::Model::Model(Mesh *mesh, Texture *texture)
{
    this->mesh = mesh;
    this->texture = texture;
	this->position = glm::vec3(0.0f);
    is_textured = true;
}

EXP::Model::~Model() {}

void EXP::Model::Draw()
{
    mesh->Draw();
}

void EXP::Model::SetID(unsigned int id)
{
    this->ID = id;
}

void EXP::Model::SetPosition(glm::vec3 position)
{
    this->position = position;
}

void EXP::Model::SetRotation(glm::vec3 rotation)
{
    this->rotation = rotation;
}

void EXP::Model::SetUnits(EXP::Model::UNITS units)
{
    this->units = units;
}

glm::mat4 EXP::Model::GetTransformationMatrix() const
{
    glm::mat4 transform = glm::mat4(1.0f);
    transform = glm::translate(transform, position);
    transform = glm::rotate(transform, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
    transform = glm::rotate(transform, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
    transform = glm::rotate(transform, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
    return transform;
}
