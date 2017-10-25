//
//  InputXY.cpp
//  EXPGL
//
//  Created by Nick Fagan on 10/24/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#include "InputXY.hpp"

EXP::InputXY::InputXY(EXP::RenderTarget *target)
{
    this->target = target;
    this->coordinates = glm::vec2(0.0f, 0.0f);
}

EXP::InputXY::~InputXY() {}

glm::vec2 EXP::InputXY::GetCoordinates() const
{
    return coordinates;
}

void EXP::InputXY::UpdateCoordinates()
{
    double x, y;
    glfwGetCursorPos(target->GetPrimaryWindow()->GetWindow(), &x, &y);
    coordinates.x = (float)x;
    coordinates.y = (float)y;
}


