//
//  Stimulus2DRenderer.cpp
//  EXPGL
//
//  Created by Nick Fagan on 10/22/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#include "Shape2DRenderer.hpp"

EXP::Shape2DRenderer::Shape2DRenderer(EXP::RenderTarget *target)
{
    this->target = target;
    shader = new EXP::Shape2DShader();
}

EXP::Shape2DRenderer::~Shape2DRenderer()
{
    delete shader;
}

glm::mat4 EXP::Shape2DRenderer::GetProjectionMatrix(Rect<float> window_rect)
{
    return glm::ortho(window_rect.get_left(), window_rect.get_right(),
                      window_rect.get_bottom(), window_rect.get_top());
}

void EXP::Shape2DRenderer::Draw(EXP::Shape2D *shape)
{
    for (unsigned i = 0; i < target->windows.size(); ++i)
    {
        EXP::Window *current = target->windows[i];
        current->MakeCurrent();
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        shader->Start();
        Rect<float> wrect = static_cast<Rect<float>>(*(current->GetRect()));
        Rect<float> srect = static_cast<Rect<float>>(target->GetFullRect());
        shader->SetMat4("view", GetProjectionMatrix(wrect));
        shader->SetMat4("model", shape->GetTransformationMatrix(wrect, srect));
        shape->Draw();
        shader->Stop();
        glfwSwapBuffers(current->GetWindow());
    }
}

