//
//  Material.hpp
//  EXPGL
//
//  Created by Nick Fagan on 10/26/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#ifndef Material_hpp
#define Material_hpp

#include <stdio.h>
#include <vector>
#include <atomic>
#include "../Render/Shader.hpp"
#include "../Resource/GLResourcePrimitive.hpp"
#include "MaterialAttribute.hpp"

namespace EXP {
    
    class Material : public GLResourcePrimitive
    {
        friend class MaterialLoader;
        
    public:
        Material();
        virtual ~Material() = default;
        virtual void Configure(EXP::Shader *shader);
    protected:
        std::vector<MaterialAttribute> attributes;
    };
}

#endif /* Material_hpp */
