//
//  MaterialTexture2D.hpp
//  EXPGL
//
//  Created by Nick Fagan on 10/26/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#ifndef MaterialTexture2D_hpp
#define MaterialTexture2D_hpp

#include <stdio.h>
#include "Material.hpp"
#include "../Texture/Texture.hpp"

namespace EXP {
    class MaterialTexture2D : public EXP::Material
    {
    public:
        MaterialTexture2D(EXP::Texture *texture);
        ~MaterialTexture2D() = default;
        
        void Configure(EXP::Shader *shader);
        int GetWidth(void) const;
        int GetHeight(void) const;
    private:
        std::atomic<EXP::Texture*> texture;
    };
}

#endif /* MaterialTexture2D_hpp */
