//
//  Model.cpp
//  EXPGL
//
//  Created by Nick Fagan on 10/22/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#include "Model.hpp"
#include <iostream>

EXP::Model::Model(EXP::Mesh *mesh, EXP::Material *material) : EXP::GLResourcePrimitive()
{
    SetMesh(mesh);
    SetMaterial(material);
    SetPosition(glm::vec3(0.0f));
    SetRotation(glm::vec3(0.0f));
    SetScale(glm::vec3(1.0f));
    SetShader(nullptr);
}

EXP::Model::~Model() {}

bool EXP::Model::Is2D() const
{
    return is_2d;
}

void EXP::Model::Draw(unsigned index)
{
    if (!shader)
    {
        std::cout << "WARNING: Attempted to draw before assigning a shader!" << std::endl;
        return;
    }
    material.load()->Configure(shader);
    mesh.load()->Draw(index);
}

void EXP::Model::Initialize(EXP::RenderTarget* target)
{
    initialize_mesh(target);
}

void EXP::Model::MakeLike(EXP::Model *model)
{
    SetShader(model->GetShader());
    SetMaterial(model->GetMaterial());
    SetPosition(model->GetPosition());
    SetRotation(model->GetRotation());
    SetScale(model->GetScale());
    SetUnits(model->GetUnits());
}

void EXP::Model::SetShader(EXP::Shader *shader)
{
    this->shader.store(shader);
}

void EXP::Model::SetMaterial(EXP::Material *material)
{
    this->material.store(material);
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

void EXP::Model::SetMesh(EXP::Mesh *mesh)
{
    this->mesh.store(mesh);
}

void EXP::Model::initialize_mesh(EXP::RenderTarget *target)
{
    mesh.load()->Initialize(target);
}

EXP::Model::UNITS EXP::Model::GetUnits() const
{
    return units;
}

glm::vec3 EXP::Model::GetPosition() const
{
    return position;
}

glm::vec3 EXP::Model::GetScale() const
{
    return scale;
}

glm::vec3 EXP::Model::GetRotation() const
{
    return rotation;
}

EXP::Shader* EXP::Model::GetShader() const
{
    return shader.load();
}

EXP::Material* EXP::Model::GetMaterial() const
{
    return material.load();
}

glm::mat4 EXP::Model::GetTransformationMatrix(EXP::Rect<float> screen) const
{
    glm::mat4 transform = glm::mat4(1.0f);
    transform = glm::translate(transform, position);
    transform = glm::rotate(transform, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
    transform = glm::rotate(transform, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
    transform = glm::rotate(transform, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
    return transform;
}
