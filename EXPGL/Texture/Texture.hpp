//
//  Texture.hpp
//  EXPGL
//
//  Created by Nick Fagan on 10/22/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#ifndef Texture_hpp
#define Texture_hpp

#include <stdio.h>
#include <glad/glad.h>

namespace EXP {
    class Texture
    {
    public:
        Texture(unsigned id);
        virtual ~Texture();
        
        virtual void Activate(unsigned offset);
    protected:
        unsigned id;
    };
}

#endif /* Texture_hpp */
