//
//  Quad.hpp
//  EXPGL
//
//  Created by Nick Fagan on 10/22/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#ifndef Quad_hpp
#define Quad_hpp

#include <stdio.h>
#include "Mesh.hpp"

namespace EXP {
    class Quad : public EXP::Mesh
    {
    public:
        Quad();
        ~Quad();
    private:
        float vertex_data[30] = {
            -1.0f, 1.0f, 0.0f, -1.0f, 1.0f,
            -1.0f, -1.0f, 0.0f, -1.0f, -1.0f,
            1.0f, -1.0f, 0.0f, 1.0f, -1.0f,
            1.0f, -1.0f, 0.0f, 1.0f, -1.0f,
            1.0f, 1.0f, 0.0f, 1.0f, 1.0f,
            -1.0f, 1.0f, 0.0f, -1.0f, 1.0f
        };
    };
}

#endif /* Quad_hpp */
