//
//  Model3D.cpp
//  EXPGL
//
//  Created by Nick Fagan on 10/27/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#include "Model3D.hpp"

EXP::Model3D::Model3D(EXP::Mesh *mesh, EXP::Material *material) : EXP::Model(mesh, material) {}

EXP::Model3D::~Model3D() {}

glm::mat4 EXP::Model3D::GetTransformationMatrix(Rect<float> window, Rect<float> screen) const
{
    return Model::GetTransformationMatrix(screen);
}
