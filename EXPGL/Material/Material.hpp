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
#include "Texture.hpp"

namespace EXP {
    class Material
    {
    public:
        Material();
        ~Material();
        virtual void Configure(Shader *shader);
    };
}

#endif /* Material_hpp */
