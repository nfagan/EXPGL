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

glm::mat4 EXP::Renderer2D::GetProjectionMatrix(Rect<float> window_rect)
{
    return glm::ortho(window_rect.get_left(), window_rect.get_right(),
                      window_rect.get_bottom(), window_rect.get_top());
}

void EXP::Renderer2D::Draw(EXP::Model2D *model, EXP::Window *window, unsigned index)
{
    shader->Start();
    Rect<float> wrect = static_cast<Rect<float>>(*(window->GetRect()));
    Rect<float> srect = static_cast<Rect<float>>(target->GetFullRect());
    shader->SetMat4("view", GetProjectionMatrix(wrect));
    shader->SetMat4("model", model->GetTransformationMatrix(wrect, srect));
    model->Draw(shader, index);
    shader->Stop();
}

