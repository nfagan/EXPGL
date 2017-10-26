//
//  Shape2DLoader.hpp
//  EXPGL
//
//  Created by Nick Fagan on 10/22/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#ifndef Shape2DLoader_hpp
#define Shape2DLoader_hpp

#include <stdio.h>
#include <unordered_map>
#include "TextureLoader.hpp"
#include "../Model/Shape2D.hpp"
#include "../Model/Rectangle.hpp"
#include "../Render/RenderTarget.hpp"

namespace EXP {
    class ModelLoader
    {
    public:
        ModelLoader(TextureLoader *texture_loader);
        ~ModelLoader();
        
        Rectangle* CreateRectangle(EXP::RenderTarget *target);
    private:
        TextureLoader *texture_loader;
        std::vector<Model*> models;
    };
}

#endif /* Shape2DLoader_hpp */
