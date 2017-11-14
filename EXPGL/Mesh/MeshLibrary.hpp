//
//  MeshLibrary.hpp
//  EXPGL
//
//  Created by Nick Fagan on 11/14/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#ifndef MeshLibrary_hpp
#define MeshLibrary_hpp

#include "Mesh.hpp"
#include "Vertex.hpp"
#include <array>
#include <math.h>

namespace EXP {
    namespace MeshLibrary {
        static const void make_quad(Mesh *mesh)
        {
            using std::array;
            
            static const float vertex_data[48] = {
                -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
                -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
                1.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
                1.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
                1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f,
                -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f
            };
            
            for (unsigned i = 0; i < 6; ++i)
            {
                Vertex vertex;
                float x = vertex_data[i*8+0];
                float y = vertex_data[i*8+1];
                float z = vertex_data[i*8+2];
                float u = vertex_data[i*8+3];
                float v = vertex_data[i*8+4];
                float nx = vertex_data[i*8+5];
                float ny = vertex_data[i*8+6];
                float nz = vertex_data[i*8+7];
                
                vertex.set_position(array<float, 3>{x, y, z});
                vertex.set_uv(array<float, 2>{u, v});
                vertex.set_normal(array<float, 3>{nx, ny, nz});
                
                mesh->AddVertex(vertex);
                mesh->SetTopology(Mesh::TRIANGLES);
            }
        }
    }
}

#endif /* MeshLibrary_hpp */
