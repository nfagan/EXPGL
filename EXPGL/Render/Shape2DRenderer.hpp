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
#include "Shape2DShader.hpp"
#include "RenderTarget.hpp"
#include "../Model/Shape2D.hpp"
#include "../Util/Colors.hpp"

namespace EXP {
    class Shape2DRenderer
    {
    public:
        Shape2DRenderer(EXP::RenderTarget *target);
        ~Shape2DRenderer();
        
        void Draw(EXP::Shape2D *shape);
        
        void SetClearColor(glm::vec3 color);
        glm::mat4 GetProjectionMatrix(Rect<float> window_rect);
    private:
        EXP::RenderTarget *target;
        EXP::Shape2DShader *shader;
        glm::vec3 clear_color = EXP::Colors::BLACK;
    };
}

#endif /* Stimulus2DRenderer_hpp */
