//
//  Stimulus2DShader.hpp
//  EXPGL
//
//  Created by Nick Fagan on 10/22/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#ifndef Stimulus2DShader_hpp
#define Stimulus2DShader_hpp

#include <stdio.h>
#include "Shader.hpp"

namespace EXP {
    class Shader2D : public Shader
    {
    public:
        Shader2D();
        ~Shader2D();
    };
}

#endif /* Stimulus2DShader_hpp */