//
//  Material.cpp
//  EXPGL
//
//  Created by Nick Fagan on 11/5/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#include <stdio.h>
#include "Material.hpp"

EXP::Material::Material() : EXP::GLResourcePrimitive() {};

void EXP::Material::Configure(EXP::Shader *shader)
{
    for (unsigned i = 0; i < attributes.size(); ++i)
    {
        attributes[i].Configure(shader);
    }
}
