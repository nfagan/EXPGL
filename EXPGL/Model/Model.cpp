//
//  Model.cpp
//  EXPGL
//
//  Created by Nick Fagan on 10/22/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#include "Model.hpp"

EXP::Model::Model(EXP::Mesh *mesh, EXP::Material *material)
{
    this->mesh = mesh;
    this->material = material;
    this->position = glm::vec3(0.0f);
    this->rotation = glm::vec3(0.0f);
    this->scale = glm::vec3(1.0f);
}

EXP::Model::~Model() {}

void EXP::Model::Draw(EXP::Shader *shader, unsigned index)
{
    material->Configure(shader);
    mesh->Draw(index);
}

void EXP::Model::set_id(unsigned int id)
{
    this->id = id;
}

unsigned EXP::Model::GetId() const
{
    return id;
}

void EXP::Model::SetMaterial(EXP::Material *material)
{
    this->material = material;
}

void EXP::Model::SetScale(glm::vec3 scale)
{
    this->scale = scale;
}

void EXP::Model::SetScale(float scale)
{
    this->scale = glm::vec3(scale);
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

void EXP::Model::InitializeMesh(EXP::RenderTarget *target)
{
    mesh->Initialize(target);
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
