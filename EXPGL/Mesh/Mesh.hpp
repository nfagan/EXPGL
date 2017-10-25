//
//  Mesh.hpp
//  EXPGL
//
//  Created by Nick Fagan on 10/22/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#ifndef Mesh_hpp
#define Mesh_hpp

#include <stdio.h>
#include "../GL_HEADERS.h"

namespace EXP {
    class Mesh
    {
    public:        
        enum TOPOLOGY {
            TRIANGLES,
            TRIANGLE_STRIP
        };
        
        Mesh();
        virtual ~Mesh();
        
        void Draw(void) const;
        void Bind(void) const;
        void Unbind(void) const;
    protected:
        unsigned vao;
        unsigned vbo;
        int n_fragments;
        int n_vertex_elements;
        int n_elements_per_vertex;
        TOPOLOGY topology = TRIANGLES;
    };
}

#endif /* Mesh_hpp */
