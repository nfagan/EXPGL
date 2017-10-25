//
//  GLContextManager.hpp
//  EXPGL
//
//  Created by Nick Fagan on 10/20/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#ifndef GLContextManager_hpp
#define GLContextManager_hpp

#include "../GL_HEADERS.h"
#include <stdio.h>
#include <vector>
#include <assert.h>
#include "Window.hpp"
#include "../Render/RenderTarget.hpp"

namespace EXP {
    
    class GLContextManager
    {
    public:
        GLContextManager();
        ~GLContextManager();
        
        bool DidInitialize(void);
        
        Window* CreateWindow(unsigned index, Window *other);
        Window* CreateWindow(unsigned index, unsigned width, unsigned height, Window *other);
        void CloseWindow(Window *window);
        
        RenderTarget* CreateRenderTarget(Window *window);
        RenderTarget* CreateRenderTarget(std::vector<EXP::Window*> windows);        
    private:
        int init_status;
        
        void init_context(void);
        void init_monitors(void);
        
        GLFWmonitor** monitors;
        int n_monitors;
        bool *has_fullscreen_window;
        
        std::vector<Window*> windows;
        std::vector<RenderTarget*> render_targets;
        
        void validate_index(unsigned index);
        void register_window(Window *window);
    };
}

#endif /* GLContextManager_hpp */
