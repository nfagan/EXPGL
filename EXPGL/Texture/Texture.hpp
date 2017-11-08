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
#include "../Resource/GLResourcePrimitive.hpp"

namespace EXP {
    class Texture : public GLResourcePrimitive
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
