//
//  TextureLoader.hpp
//  EXPGL
//
//  Created by Nick Fagan on 10/22/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#ifndef TextureLoader_hpp
#define TextureLoader_hpp

#include <stdio.h>
#include <vector>
#include <unordered_map>
#include "../Texture/Texture2D.hpp"
#include "../GL_HEADERS.h"

namespace EXP {
    class TextureLoader
    {
    public:
        TextureLoader(void);
        ~TextureLoader(void);
        
        Texture2D* GetTexture2D(const char* filename);
    private:
        std::unordered_map<const char*, Texture2D*> textures_2d;
    };
}

#endif /* TextureLoader_hpp */
