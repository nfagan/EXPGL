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
        Texture() = default;
        Texture(unsigned id);
        Texture(unsigned id, int width, int height);
        virtual ~Texture();
        
        virtual void Activate(void);
        virtual void SetIndex(unsigned index);
        
        int GetWidth(void) const;
        int GetHeight(void) const;
        int GetIndex(void) const;
    protected:
        unsigned index;
        unsigned id;
        int width;
        int height;
    };
}

#endif /* Texture_hpp */
