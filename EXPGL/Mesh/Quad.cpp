//
//  Quad.cpp
//  EXPGL
//
//  Created by Nick Fagan on 10/22/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#include "Quad.hpp"

EXP::Quad::Quad() : EXP::Mesh()
{
    //  VERTEX DATA
    n_fragments = 6;
    n_vertex_elements = 30;
    n_elements_per_vertex = 5;
    
    //  TOPOLOGY
    topology = EXP::Mesh::TRIANGLES;
    
    //  CONFIGURE BUFFERS
    glGenBuffers(1, &vbo);
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    //  store vertices in VBO
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * n_vertex_elements, vertex_data, GL_STATIC_DRAW);
    GLsizei stride = n_elements_per_vertex * sizeof(float);
    //  position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, (void*)0);
    glEnableVertexAttribArray(0);
    //  tex coords
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, stride, (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);
    glBindVertexArray(0);
}

EXP::Quad::~Quad() {}
