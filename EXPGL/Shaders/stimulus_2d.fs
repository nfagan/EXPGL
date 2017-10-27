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
}
