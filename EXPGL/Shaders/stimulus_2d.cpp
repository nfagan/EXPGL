//
//  stimulus_2d.cpp
//  EXPGL
//
//  Created by Nick Fagan on 10/28/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#include <stdio.h>

namespace EXP {
    namespace Shaders {
        namespace stimulus_2d_shader {
            static const char *fragment = R"(
                #version 330 core
            
                out vec4 FragColor;
            
                in vec2 TextureCoordinates;
            
                uniform bool is_textured;
                uniform sampler2D image;
                uniform vec3 albedo;
            
                void main()
                {
                    if (is_textured) {
                        FragColor = vec4(texture(image, TextureCoordinates).rgb, 1.0f);
                    } else {
                        FragColor = vec4(albedo, 1.0f);
                    }
                })";
            
            static const char *vertex = R"(
                #version 330 core
                layout (location = 0) in vec3 position;
                layout (location = 1) in vec2 tex_coords;
            
                uniform mat4 model;
                uniform mat4 view;
            
                out vec2 TextureCoordinates;
            
                void main()
                {
                    TextureCoordinates = tex_coords;
                    gl_Position = view * model * vec4(position, 1.0f);
                })";
        }
    }
}
