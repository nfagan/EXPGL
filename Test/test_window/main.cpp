//
//  main.cpp
//  test_window
//
//  Created by Nick Fagan on 10/25/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#include <iostream>
#include <EXPGL/Context/GLContextManager.hpp>
#include <EXPGL/Render/Renderer.hpp>
#include <EXPGL/Loaders/ResourceManager.hpp>
#include <EXPGL/Util/Rect.hpp>
#include <EXPGL/Util/Positions2D.hpp>
#include <EXPGL/Input/InputXY.hpp>

int main(int argc, const char * argv[]) {
    
    using namespace EXP;
    
    GLContextManager *context_manager = new GLContextManager();
    ResourceManager *resource_manager = new ResourceManager();
    
    if (!context_manager->DidInitialize())
    {
        fprintf(stderr, "Error initializing");
        delete resource_manager;
        delete context_manager;
        return EXIT_FAILURE;
    }
    
    //    Window *window = context_manager->CreateWindow(0, 400, 400, NULL);
    Window *window = context_manager->OpenWindow(0, NULL);
    //    Window *window3 = context_manager->CreateWindow(0, 400, 400, window);
    
    //    std::vector<Window*> windows = { window, window2, window3 };
    std::vector<Window*> windows = { window };
    RenderTarget *target = context_manager->CreateRenderTarget(windows);
    target->SetWindowOffsets(RenderTarget::HORIZONTAL);
    
    Renderer *renderer = new Renderer(target);
    Rectangle *rectangle = resource_manager->CreateRectangle();
    
    renderer->SetClearColor(Colors::WHITE);
    glm::vec2 rect_pos = Positions2D::CENTER;
    float step_amount = 0.005f;
    
    rectangle->SetUnits(Model::MIXED);
    rectangle->SetDimensions(50.0f, 50.0f);
    rectangle->SetPosition(rect_pos);
    
    windows[0]->Focus();
    
    double mouse_x, mouse_y;
    
    InputXY* input = new InputXY(target);
    
    while (true)
    {
        renderer->Draw(rectangle);
        if (glfwGetKey(window->GetWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
        {
            context_manager->CloseWindow(window);
            break;
        }
        if (glfwGetKey(window->GetWindow(), GLFW_KEY_A) == GLFW_PRESS)
        {
            rect_pos.x -= step_amount;
            rectangle->SetPosition(rect_pos);
        }
        if (glfwGetKey(window->GetWindow(), GLFW_KEY_D) == GLFW_PRESS)
        {
            rect_pos.x += step_amount;
            rectangle->SetPosition(rect_pos);
        }
        if (glfwGetKey(window->GetWindow(), GLFW_KEY_W) == GLFW_PRESS)
        {
            rect_pos.y -= step_amount;
            rectangle->SetPosition(rect_pos);
        }
        if (glfwGetKey(window->GetWindow(), GLFW_KEY_S) == GLFW_PRESS)
        {
            rect_pos.y += step_amount;
            rectangle->SetPosition(rect_pos);
        }
        if (glfwGetKey(window->GetWindow(), GLFW_KEY_C) == GLFW_PRESS)
        {
            rect_pos.x = 0.5f;
            rect_pos.y = 0.5f;
            rectangle->SetPosition(rect_pos);
        }
        
        glfwGetCursorPos(window->GetWindow(), &mouse_x, &mouse_y);
        
        glfwPollEvents();
    }
    
    delete context_manager;
    delete resource_manager;
    delete renderer;
    
    return 0;
}
