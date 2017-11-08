//
//  bare_2d.cpp
//  EXPGL
//
//  Created by Nick Fagan on 11/2/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#include <stdio.h>

namespace EXP {
    namespace Shaders {
        namespace bare_2d {
            static const char *fragment = R"(
                #version 330 core
            
                void main()
                {
                    FragColor = vec4(0.0f, 1.0f, 0.0f, 1.0f);
                })";
            
            static const char *vertex = R"(
                #version 330 core
                layout (location = 0) in vec3 position;
            
                void main()
                {
                    gl_Position = vec4(position, 1.0f);
                })";
        }
    }
}
