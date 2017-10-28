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
#ifdef EXPGL__INPUTXY__DO_ATOMIC
    x.store(0.0f);
    y.store(0.0f);
#else
    x = 0.0f;
    y = 0.0f;
#endif
}

EXP::InputXY::~InputXY() {}

glm::vec2 EXP::InputXY::GetCoordinates() const
{
#ifdef EXPGL__INPUTXY__DO_ATOMIC
    return glm::vec2(x.load(), y.load());
#else
    return glm::vec2(x, y);
#endif
}

void EXP::InputXY::UpdateCoordinates()
{
    double x_, y_;
    glfwGetCursorPos(target->GetPrimaryWindow()->GetWindow(), &x_, &y_);
#ifdef EXPGL__INPUTXY__DO_ATOMIC
    x.store((float)x_);
    y.store((float)y_);
#else
    x = x_;
    y = y_;
#endif
}

void EXP::InputXY::PrintCoordinates() const
{
#ifdef EXPGL__INPUTXY__DO_ATOMIC
    fprintf(stderr, "\nInputXY: X: %0.3f, Y: %0.3f", x.load(), y.load());
#else
    fprintf(stderr, "\nInputXY: X: %0.3f, Y: %0.3f", x, y);
#endif
}


