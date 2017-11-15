//
//  GLResourcePrimitive.hpp
//  EXPGL
//
//  Created by Nick Fagan on 11/5/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#ifndef GLResourcePrimitive_hpp
#define GLResourcePrimitive_hpp

#include <stdio.h>
#include "GLResourceIdentifier.hpp"

namespace EXP {
    
    class RenderTarget;
    
    class GLResourcePrimitive
    {
        friend class GLResourceManager;
    public:
        GLResourcePrimitive();
        ~GLResourcePrimitive() = default;
        
        virtual GLResourceIdentifier GetIdentifier(void) const;
        
        virtual void Initialize(RenderTarget *target);
        
        virtual void SetTag(std::string tag);
    protected:
        virtual void set_identifier(GLResourceIdentifier identifier);
        GLResourceIdentifier identifier;
    };
}

#endif /* GLResourcePrimitive_hpp */
