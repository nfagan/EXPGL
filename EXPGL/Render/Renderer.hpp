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
#include <glm/glm.hpp>
#include "Renderer2D.hpp"
#include "../Model/Model2D.hpp"
#include "../Model/Model3D.hpp"
#include "../Util/Colors.hpp"

namespace EXP {
    class Renderer
    {
    public:
        Renderer(EXP::RenderTarget *target);
        ~Renderer();
        
        void SetClearColor(glm::vec3 color);
        
        void Queue(EXP::Model2D *model);
        void Queue(EXP::Model3D *model);
        
        void Draw(void);
    private:
        std::vector<EXP::Model2D*> models_2d;
        std::vector<EXP::Model3D*> models_3d;
        EXP::Renderer2D *renderer_2d;
        EXP::RenderTarget *target;
        glm::vec3 clear_color = EXP::Colors::BLACK;
        
        void prepare_context(EXP::Window *window);
        void draw(EXP::Model2D *model, EXP::Window *window, unsigned index);
        void swap_buffers(EXP::Window *window);
    };
}

#endif /* Renderer_hpp */
