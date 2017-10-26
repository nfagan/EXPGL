//
//  Mesh.cpp
//  EXPGL
//
//  Created by Nick Fagan on 10/22/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#include "Mesh.hpp"

EXP::Mesh::Mesh() {}

EXP::Mesh::~Mesh() {
    for (unsigned i = 0; i < n_vaos; ++i) {
        glDeleteVertexArrays(1, &vaos[i]);
    }
    delete[] vaos;
    glDeleteBuffers(1, &vbo);
}

void EXP::Mesh::Initialize(EXP::RenderTarget *target)
{
    vaos = new unsigned[target->Size()];
    is_initialized = true;
}

void EXP::Mesh::Bind(unsigned index) const
{
    glBindVertexArray(vaos[index]);
}

void EXP::Mesh::Unbind() const
{
    glBindVertexArray(0);
}

bool EXP::Mesh::IsInitialized() const
{
    return is_initialized;
}

void EXP::Mesh::Draw(unsigned index) const
{
    Bind(index);
    switch (topology) {
        case TRIANGLES:
            glDrawArrays(GL_TRIANGLES, 0, n_fragments);
            break;
        default:
            //  Not yet implemented
            assert(false);
            break;
    }
    Unbind();
}
