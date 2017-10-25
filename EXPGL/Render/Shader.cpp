//
//  Shader.cpp
//  EXPGL
//
//  Created by Nick Fagan on 10/22/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#include "Shader.hpp"

EXP::Shader::Shader() {};

EXP::Shader::~Shader()
{
    glDeleteProgram(ID);
}

void EXP::Shader::Start()
{
    glUseProgram(ID);
}

void EXP::Shader::Stop()
{
    glUseProgram(0);
}

bool EXP::Shader::Attach(const char *filename, EXP::Shader::SHADER_TYPES shader_type)
{
    std::string code;
    std::ifstream shader_file;
    
    shader_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    
    try {
        shader_file.open(filename);
        std::stringstream shader_stream;
        shader_stream << shader_file.rdbuf();
        shader_file.close();
        code = shader_stream.str();
    } catch (std::ifstream::failure e) {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
        return false;
    }
    
    const char* shader_code = code.c_str();
    unsigned shader_id;
    std::string shader_type_name;
    
    switch (shader_type)
    {
        case VERTEX:
            shader_id = glCreateShader(GL_VERTEX_SHADER);
            shader_type_name = "VERTEX";
            break;
        case FRAGMENT:
            shader_id = glCreateShader(GL_FRAGMENT_SHADER);
            shader_type_name = "FRAGMENT";
            break;
        case GEOMETRY:
            shader_id = glCreateShader(GL_GEOMETRY_SHADER);
            shader_type_name = "GEOMETRY";
            break;
        default:
            assert(false);
    }
    
    glShaderSource(shader_id, 1, &shader_code, nullptr);
    glCompileShader(shader_id);
    
    shader_ids[n_shader_ids++] = shader_id;
    
    return (bool)check_compile_errors(shader_id, shader_type_name);
}

void EXP::Shader::SetMat4(const char *name, glm::mat4 value) const
{
    unsigned int loc = glGetUniformLocation(ID, name);
    glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(value));
}

void EXP::Shader::SetInt(const char *name, int value) const
{
    glUniform1i(glGetUniformLocation(ID, name), value);
}

void EXP::Shader::SetBool(const char *name, bool value) const
{
    glUniform1i(glGetUniformLocation(ID, name), (int)value);
}

void EXP::Shader::SetFloat(const char *name, float value) const
{
    glUniform1f(glGetUniformLocation(ID, name), value);
}

bool EXP::Shader::Link()
{
    ID = glCreateProgram();
    for (int i = 0; i < n_shader_ids; ++i)
    {
        glAttachShader(ID, shader_ids[i]);
    }
    
    glLinkProgram(ID);
    
    int success = check_link_errors(ID);
    
    for (int i = 0; i < n_shader_ids; ++i)
    {
        glDeleteShader(shader_ids[i]);
    }
    
    return (bool)success;
}

int EXP::Shader::check_compile_errors(unsigned id, std::string shader_type_name)
{
    
    int success;
    char info_log[1024];
    
    glGetShaderiv(id, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(id, 1024, NULL, info_log);
        std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << shader_type_name << "\n" << info_log << "\n -- --------------------------------------------------- -- " << std::endl;
    }
    
    return success;
}

int EXP::Shader::check_link_errors(unsigned id)
{
    int success;
    char info_log[1024];
    
    glGetProgramiv(id, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(id, 1024, NULL, info_log);
        std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << "\n" << info_log << "\n -- --------------------------------------------------- -- " << std::endl;
    }
    return success;
}
