//
//  MaterialLoader.hpp
//  EXPGL
//
//  Created by Nick Fagan on 10/26/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#ifndef MaterialLoader_hpp
#define MaterialLoader_hpp

#include <stdio.h>
#include "Loader.hpp"
#include "../Material/Material.hpp"

namespace EXP {
    class MaterialLoader : public Loader<Material>
    {
    public:
        MaterialLoader(EXP::TextureLoader *texture_loader) : EXP::Loader<EXP::Material>(texture_loader) {};
        ~MaterialLoader(void) {};
        
        template<typename T, typename... A>
        T* CreateMaterial(A... args)
        {
            static_assert(std::is_base_of<EXP::Material, T>::value, "Template type must be derived from Material.");
            T* val = new T(args...);
            items.push_back(val);
            return val;
        }
    };
}

#endif /* MaterialLoader_hpp */
