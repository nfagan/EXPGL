//
//  Loader.hpp
//  EXPGL
//
//  Created by Nick Fagan on 10/26/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#ifndef Loader_hpp
#define Loader_hpp

#include <stdio.h>
#include <vector>
#include "TextureLoader.hpp"

namespace EXP {
    template<typename T>
    class Loader
    {
    public:
        Loader(EXP::TextureLoader *texture_loader)
        {
            this->texture_loader = texture_loader;
        }
        
        virtual ~Loader()
        {
            for (unsigned i = 0; i < items.size(); ++i)
            {
                delete items[i];
            }
        }
    protected:
        EXP::TextureLoader *texture_loader;
        std::vector<T*> items;
    };
}

#endif /* Loader_hpp */
