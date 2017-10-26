//
//  Stimulus2DRenderer.cpp
//  EXPGL
//
//  Created by Nick Fagan on 10/22/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#include "Renderer2D.hpp"

EXP::Renderer2D::Renderer2D(EXP::RenderTarget *target)
{
    this->target = target;
    shader = new EXP::Shader2D();
}

EXP::Renderer2D::~Renderer2D()
{
    delete shader;
}

void EXP::Renderer2D::SetClearColor(glm::vec3 color)
{
    clear_color = color;
}

glm::mat4 EXP::Renderer2D::GetProjectionMatrix(Rect<float> window_rect)
{
    return glm::ortho(window_rect.get_left(), window_rect.get_right(),
                      window_rect.get_bottom(), window_rect.get_top());
}

void EXP::Renderer2D::Draw(EXP::Shape2D *shape)
{
    for (unsigned i = 0; i < target->Size(); ++i)
    {
        EXP::Window *current = target->GetWindow(i);
        current->MakeCurrent();
        glClearColor(clear_color.x, clear_color.y, clear_color.z, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        shader->Start();
        Rect<float> wrect = static_cast<Rect<float>>(*(current->GetRect()));
        Rect<float> srect = static_cast<Rect<float>>(target->GetFullRect());
        shader->SetMat4("view", GetProjectionMatrix(wrect));
        shader->SetMat4("model", shape->GetTransformationMatrix(wrect, srect));
        shape->Draw(i);
        shader->Stop();
        glfwSwapBuffers(current->GetWindow());
    }
}

