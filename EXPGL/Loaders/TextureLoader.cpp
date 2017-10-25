//
//  TextureLoader.cpp
//  EXPGL
//
//  Created by Nick Fagan on 10/22/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#include "TextureLoader.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

EXP::TextureLoader::TextureLoader() {}

EXP::TextureLoader::~TextureLoader() {
    for (auto it = textures_2d.begin(); it != textures_2d.end(); ++it)
    {
        delete it->second;
    }
}

EXP::Texture2D* EXP::TextureLoader::GetTexture2D(const char *filename)
{
    if (textures_2d.find(filename) != textures_2d.end())
    {
        return textures_2d[filename];
    }
    
    unsigned int texture_id;
    glGenTextures(1, &texture_id);
    
    int width, height, n_components;
    unsigned char *data = stbi_load(filename, &width, &height, &n_components, 0);
    
    if (data) {
        GLenum format;
        if (n_components == 1)
        {
            format = GL_RED;
        }
        else if (n_components == 3)
        {
            format = GL_RGB;
        }
        else if (n_components == 4)
        {
            format = GL_RGBA;
        }
        else
        {
            assert(false);
        }
        
        glBindTexture(GL_TEXTURE_2D, texture_id);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        
        stbi_image_free(data);
    } else {
        fprintf(stderr, "Could not load texture %s", filename);
        stbi_image_free(data);
        return NULL;
    }
    
    EXP::Texture2D *texture = new EXP::Texture2D(texture_id, width, height);
    textures_2d[filename] = texture;
    
    return texture;
}
