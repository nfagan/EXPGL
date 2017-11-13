//
//  generic.cpp
//  EXPGL
//
//  Created by Nick Fagan on 11/12/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

namespace EXP {
    namespace Shaders {
        namespace generic {
            static const char *fragment = R"(
                #version 330 core
            
                out vec4 FragColor;
                in vec2 TextureCoordinates;
            
                uniform bool albedo__use_texture;
                uniform sampler2D albedo__value_sampler2d;
                uniform vec3 albedo__value_vec3;
            
                void main()
                {
                    if (albedo__use_texture) {
                        FragColor = vec4(texture(albedo__value_sampler2d, TextureCoordinates).rgb, 1.0f);
                    } else {
                        FragColor = vec4(albedo__value_vec3, 1.0f);
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
