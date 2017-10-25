//
//  Stimulus2DShader.cpp
//  EXPGL
//
//  Created by Nick Fagan on 10/22/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#include "Shape2DShader.hpp"
#include "../Util/Paths.hpp"

EXP::Shape2DShader::Shape2DShader() : EXP::Shader()
{
    std::string base_shader_name = EXP::PATHS::get_stimulus_2d_shader_name();
    
    std::string shader_dir = EXP::PATHS::get_shader_dir();
    std::string vs_path = base_shader_name + ".vs";
    std::string fs_path = base_shader_name + ".fs";
    
    bool vs_result, fs_result, link_result;
    vs_result = this->Attach(vs_path.c_str(), VERTEX);
    fs_result = this->Attach(fs_path.c_str(), FRAGMENT);
    link_result = this->Link();
    
    assert(vs_result && fs_result && link_result);
}

EXP::Shape2DShader::~Shape2DShader() {}
