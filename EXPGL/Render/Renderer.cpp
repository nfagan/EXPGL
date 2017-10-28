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

void EXP::Renderer::Draw(void)
{
    for (unsigned i = 0; i < target->Size(); ++i)
    {
        EXP::Window *window = target->GetWindow(i);
        prepare_context(window);
        for (unsigned j = 0; j < models_2d.size(); ++j)
        {
            draw(models_2d[j], window, i);
        }
        for (unsigned j = 0; j < models_3d.size(); ++j)
        {
            //  3D not yet implemented
            assert(false);
        }
        swap_buffers(window);
    }
    models_2d.clear();
    models_3d.clear();
}

void EXP::Renderer::Queue(EXP::Model2D *model)
{
    models_2d.push_back(model);
}

void EXP::Renderer::Queue(EXP::Model3D *model)
{
    models_3d.push_back(model);
}

void EXP::Renderer::SetClearColor(glm::vec3 color)
{
    clear_color = color;
}

void EXP::Renderer::prepare_context(EXP::Window *window)
{
    window->MakeCurrent();
    glClearColor(clear_color.x, clear_color.y, clear_color.z, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void EXP::Renderer::draw(EXP::Model2D *model, EXP::Window *window, unsigned index)
{
    renderer_2d->Draw(model, window, index);
}

void EXP::Renderer::swap_buffers(EXP::Window *window)
{
    glfwSwapBuffers(window->GetWindow());
}
