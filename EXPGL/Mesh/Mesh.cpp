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
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
}

void EXP::Mesh::Bind() const
{
    glBindVertexArray(vao);
}

void EXP::Mesh::Unbind() const
{
    glBindVertexArray(0);
}

void EXP::Mesh::Draw() const
{
    Bind();
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
