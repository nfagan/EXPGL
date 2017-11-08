//
//  GLResourcePrimitive.cpp
//  EXPGL
//
//  Created by Nick Fagan on 11/5/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#include "GLResourcePrimitive.hpp"
#include <iostream>

EXP::GLResourcePrimitive::GLResourcePrimitive() {
    identifier = EXP::GLResourceIdentifier();
};

EXP::GLResourcePrimitive::~GLResourcePrimitive() {};

void EXP::GLResourcePrimitive::Initialize(EXP::RenderTarget *target) {};

EXP::GLResourceIdentifier EXP::GLResourcePrimitive::GetIdentifier() const
{
    return identifier;
}

void EXP::GLResourcePrimitive::SetTag(std::string tag)
{
    identifier.SetTag(tag);
}

void EXP::GLResourcePrimitive::set_identifier(EXP::GLResourceIdentifier identifier)
{
    this->identifier = identifier;
}
