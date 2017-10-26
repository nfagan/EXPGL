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
    this->target = target;
    this->renderer_2d = new Renderer2D(target);
}

EXP::Renderer::~Renderer()
{
    delete renderer_2d;
}

void EXP::Renderer::Draw(EXP::Shape2D *shape)
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
    for (int i = 0; i < target->windows.size(); ++i)
    {
        target->windows[i]->MakeCurrent();
        glfwSwapBuffers(target->windows[i]->GetWindow());
    }
}