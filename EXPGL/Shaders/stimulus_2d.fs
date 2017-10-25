#version 330 core

out vec4 FragColor;

uniform sampler2D image;

void main()
{
    FragColor = vec4(0.0f, 1.0f, 1.0f, 1.0f);
}
