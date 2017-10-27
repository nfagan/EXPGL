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
#include "../Render/Shader.hpp"

namespace EXP {
    class Material
    {
    public:
        Material() {};
        virtual ~Material() {};
        virtual void Configure(EXP::Shader *shader) {};
    };
}

#endif /* Material_hpp */
