//
//  GLResourceLoader.hpp
//  EXPGL
//
//  Created by Nick Fagan on 11/5/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#ifndef GLResourceLoader_hpp
#define GLResourceLoader_hpp

#include <stdio.h>

#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_map>
#include "TextureLoader.hpp"
#include "../Util/EXPGL_ASSERT.hpp"
#include "../Resource/GLResourcePrimitive.hpp"
#include "../Resource/GLResourceIdentifier.hpp"
#include <iostream>

namespace EXP {
    class GLResourceLoader
    {
    public:
        GLResourceLoader(EXP::TextureLoader *texture_loader)
        {
            this->texture_loader = texture_loader;
            n_items = 0;
        }
    protected:
        EXP::TextureLoader *texture_loader;
        std::vector<GLResourcePrimitive*> items;
        std::unordered_map<const char*, unsigned int> indices;
        unsigned n_items;
    };
}

#endif /* GLResourceLoader_hpp */
