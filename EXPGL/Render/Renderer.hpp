//
//  Renderer.hpp
//  EXPGL
//
//  Created by Nick Fagan on 10/22/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#ifndef Renderer_hpp
#define Renderer_hpp

#include <stdio.h>
#include "Shape2DRenderer.hpp"
#include "../Model/Shape2D.hpp"

namespace EXP {
    class Renderer
    {
    public:
        Renderer(EXP::RenderTarget *target);
        ~Renderer();
        
        void PrepareContext(void);
        void Draw(Shape2D *shape);
        void Display(void);
    private:
        EXP::Shape2DRenderer *shape_2d_renderer;
        EXP::RenderTarget *target;
    };
}

#endif /* Renderer_hpp */
