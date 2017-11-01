//
//  InputKeyboard.cpp
//  EXPGL
//
//  Created by Nick Fagan on 10/26/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#include "InputKeyboard.hpp"

EXP::InputKeyboard::InputKeyboard(EXP::RenderTarget *target)
{
    this->target = target;
}

EXP::InputKeyboard::~InputKeyboard() {};

void EXP::InputKeyboard::Update() {};

bool EXP::InputKeyboard::KeyDown(int id) const
{
    return glfwGetKey(target->GetPrimaryWindow()->GetWindow(), id) == GLFW_PRESS;
}
