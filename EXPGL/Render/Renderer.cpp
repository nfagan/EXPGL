//
//  Renderer.cpp
//  EXPGL
//
//  Created by Nick Fagan on 10/22/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#include "Renderer.hpp"

EXP::Renderer::Renderer(EXP::RenderTarget *target)
{
    target->GetPrimaryWindow()->MakeCurrent();
    this->target = target;
    this->renderer_2d = new Renderer2D(target);
}

EXP::Renderer::~Renderer()
{
    delete renderer_2d;
}

void EXP::Renderer::Draw(EXP::Model2D *shape)
{
    renderer_2d->Draw(shape);
}

void EXP::Renderer::SetClearColor(glm::vec3 color)
{
    clear_color = color;
    renderer_2d->SetClearColor(color);
}

void EXP::Renderer::Display()
{
    for (int i = 0; i < target->Size(); ++i)
    {
        target->GetWindow(i)->MakeCurrent();
        glfwSwapBuffers(target->GetWindow(i)->GetWindow());
    }
}
