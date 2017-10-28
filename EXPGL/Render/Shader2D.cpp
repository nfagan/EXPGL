//
//  Stimulus2DShader.cpp
//  EXPGL
//
//  Created by Nick Fagan on 10/22/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#include "Shader2D.hpp"

#include "../Shaders/stimulus_2d.cpp"

EXP::Shader2D::Shader2D() : EXP::Shader()
{
//    std::string vs_code = EXP::Shaders::stimulus_2d_shader::vertex;
//    std::string fs_code = EXP::Shaders::stimulus_2d_shader::fragment;
    const char *vs_code = EXP::Shaders::stimulus_2d_shader::vertex;
    const char *fs_code = EXP::Shaders::stimulus_2d_shader::fragment;
    
    bool vs_result, fs_result, link_result;
    
    vs_result = this->AttachFromSource(vs_code, VERTEX);
    fs_result = this->AttachFromSource(fs_code, FRAGMENT);
    link_result = this->Link();
    
    assert(vs_result && fs_result && link_result);
}

EXP::Shader2D::~Shader2D() {}
