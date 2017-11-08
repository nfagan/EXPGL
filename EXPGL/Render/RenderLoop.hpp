//
//  RenderLoop.hpp
//  EXPGL
//
//  Created by Nick Fagan on 11/4/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#ifndef RenderLoop_hpp
#define RenderLoop_hpp

#include <stdio.h>
#include <atomic>
#include <vector>
#include <functional>
#include <unordered_map>
#include <EXPUtil/thread/spinlock.hpp>
#include "Renderer.hpp"

namespace EXP {
    
    class Model;
    
    class RenderLoop
    {
    public:
        RenderLoop(EXP::Renderer *renderer);
        ~RenderLoop();
        
        void Loop(void);
        void CancelLoop(void);
        void Queue(const std::vector<Model*> &models);
        void ClearQueue(void);
        void OnLoop(std::function<void(EXP::RenderLoop*)> on_loop);
        void OnceDrawReady(std::function<void(EXP::RenderLoop*)> once_ready);
        
    private:
        spinlock on_loop_lock;
        spinlock queue_lock;
        bool is_beginning = false;
        std::atomic<bool> called_once_draw_ready;
        std::atomic<bool> should_loop;
        std::vector<EXP::Model*> draw_queue;
        std::unordered_map<unsigned int, bool> already_queued;
        std::function<void(EXP::RenderLoop*)> on_loop = &EXP::RenderLoop::empty;
        std::function<void(EXP::RenderLoop*)> once_draw_ready = &EXP::RenderLoop::empty;
        
        void empty();
        void user_loop(void);
        void render_loop(void);
        void draw_ready(void);
        
        EXP::Renderer *renderer = nullptr;
    };
}

#endif /* RenderLoop_hpp */
