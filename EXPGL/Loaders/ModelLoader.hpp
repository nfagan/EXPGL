//
//  Model2DLoader.hpp
//  EXPGL
//
//  Created by Nick Fagan on 10/22/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#ifndef Model2DLoader_hpp
#define Model2DLoader_hpp

#include <stdio.h>
#include <unordered_map>
#include "Loader.hpp"
#include "../Model/Rectangle.hpp"
#include "../Render/RenderTarget.hpp"

namespace EXP {
    class ModelLoader : public Loader<EXP::Model>
    {
    public:
        ModelLoader(TextureLoader *texture_loader);
        ~ModelLoader(void) {};
        
        template<typename T, typename... A>
        T* CreateModel(EXP::RenderTarget *target, A... args)
        {
            T* item = new T(args...);
            item->InitializeMesh(target);
            item->set_id(items.size());
            items.push_back(item);
            return item;
        }
    };
}

#endif /* Model2DLoader_hpp */
