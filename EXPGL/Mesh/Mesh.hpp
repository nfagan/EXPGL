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
#include "../Render/RenderTarget.hpp"

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
        
        virtual void Initialize(EXP::RenderTarget *target);
        virtual bool IsInitialized(void) const;
        virtual void Draw(unsigned index) const;
        virtual void Bind(unsigned index) const;
        virtual void Unbind() const;
    protected:
        unsigned *vaos;
        unsigned vbo;
        int n_vaos;
        int n_fragments;
        int n_vertex_elements;
        int n_elements_per_vertex;
        TOPOLOGY topology = TRIANGLES;
        bool is_initialized = false;
    };
}

#endif /* Mesh_hpp */
