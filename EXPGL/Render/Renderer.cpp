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
    this->shape_2d_renderer = new Shape2DRenderer(target);
}

EXP::Renderer::~Renderer()
{
    delete shape_2d_renderer;
}

void EXP::Renderer::Draw(EXP::Shape2D *shape)
{
    shape_2d_renderer->Draw(shape);
}

void EXP::Renderer::Display()
{
    for (int i = 0; i < target->windows.size(); ++i)
    {
        target->windows[i]->MakeCurrent();
        glfwSwapBuffers(target->windows[i]->GetWindow());
    }
}
