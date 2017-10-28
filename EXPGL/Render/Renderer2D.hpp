//
//  Stimulus2DRenderer.hpp
//  EXPGL
//
//  Created by Nick Fagan on 10/22/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#ifndef Stimulus2DRenderer_hpp
#define Stimulus2DRenderer_hpp

#include <stdio.h>
#include <glm/glm.hpp>
#include "Shader2D.hpp"
#include "RenderTarget.hpp"
#include "../Model/Model2D.hpp"
#include "../Util/Colors.hpp"

namespace EXP {
    class Renderer2D
    {
    public:
        Renderer2D(EXP::RenderTarget *target);
        ~Renderer2D(void);
        
        void Draw(EXP::Model2D *model, EXP::Window *window, unsigned index);
        
        glm::mat4 GetProjectionMatrix(Rect<float> window_rect);
    private:
        EXP::RenderTarget *target;
        EXP::Shader2D *shader;
    };
}

#endif /* Stimulus2DRenderer_hpp */
