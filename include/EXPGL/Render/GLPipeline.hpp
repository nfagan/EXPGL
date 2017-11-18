//
//  GLPipeline.hpp
//  EXPGL
//
//  Created by Nick Fagan on 11/18/17.
//

#ifndef GLPipeline_hpp
#define GLPipeline_hpp

#include <EXPGL/Context/GLContextManager.hpp>
#include <EXPGL/Context/Window.hpp>
#include <EXPGL/Render/Renderer.hpp>
#include <EXPGL/Render/RenderLoop.hpp>
#include <EXPGL/Loaders/GLResourceManager.hpp>
#include <cassert>

namespace EXP {
    class GLPipeline
    {
    public:
        GLPipeline(GLContextManager *manager) : context(manager)
        {
            is_initialized = false;
        }
        
        ~GLPipeline()
        {
            delete resource;
            delete renderer;
            delete loop;
        }
        
        void Begin(int index = 0)
        {
            assert(context);
            target = context->CreateRenderTarget(context->OpenWindow(0, nullptr));
            begin(target);
            
        }
        void Begin(int index, int width, int height)
        {
            assert(context);
            target = context->CreateRenderTarget(context->OpenWindow(0, width, height, nullptr));
            begin(target);
        }
        
        Renderer* GetRenderer()
        {
            ensure_initialized();
            return renderer;
        }
        
        RenderLoop* GetLoop()
        {
            ensure_initialized();
            return loop;
        }
        
        GLResourceManager* GetResource()
        {
            ensure_initialized();
            return resource;
        }
        
        RenderTarget* GetTarget() const
        {
            ensure_initialized();
            return target;
        }
        
    private:
        bool is_initialized;
        GLContextManager *context;
        RenderTarget *target;
        Renderer *renderer;
        GLResourceManager *resource;
        RenderLoop *loop;
        
        void ensure_initialized(void) const
        {
            if (!is_initialized)
            {
                throw std::runtime_error("A call to begin() must precede item access.");
            }
        }
        
        void begin(RenderTarget *target)
        {
            resource = new GLResourceManager(target);
            renderer = new Renderer(target);
            loop = new RenderLoop(renderer);
            is_initialized = true;
        }
    };
}

#endif /* GLPipeline_hpp */
