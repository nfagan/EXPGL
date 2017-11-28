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
    
    ~GLPipeline() = default;
    
    void Begin(int index = 0)
    {
        assert(context);
        target = context->CreateRenderTarget(context->OpenWindow(index, nullptr));
        begin(target);
        
    }
    void Begin(int index, int width, int height)
    {
        assert(context);
        target = context->CreateRenderTarget(context->OpenWindow(index, width, height, nullptr));
        begin(target);
    }
    
    std::shared_ptr<Renderer>& GetRenderer()
    {
        ensure_initialized();
        return renderer;
    }
    
    std::shared_ptr<RenderLoop>& GetLoop()
    {
        ensure_initialized();
        return loop;
    }
    
    std::shared_ptr<GLResourceManager>& GetResource()
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
    std::shared_ptr<Renderer> renderer;
    std::shared_ptr<GLResourceManager> resource;
    std::shared_ptr<RenderLoop> loop;
    
    void ensure_initialized(void) const
    {
        if (!is_initialized)
        {
            throw std::runtime_error("A call to begin() must precede item access.");
        }
    }
    
    void begin(RenderTarget *target)
    {
        resource = std::make_shared<GLResourceManager>(target);
        renderer = std::make_shared<Renderer>(target);
        loop = std::make_shared<RenderLoop>(renderer);
        is_initialized = true;
    }
};
}

#endif /* GLPipeline_hpp */
