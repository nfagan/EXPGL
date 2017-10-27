//
//  multiple_windows.cpp
//  EXPGL
//
//  Created by Nick Fagan on 10/26/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#include <iostream>
#include <EXPGL/Context/GLContextManager.hpp>
#include <EXPGL/Render/Renderer.hpp>
#include <EXPGL/Loaders/ResourceManager.hpp>
#include <EXPGL/Util/Rect.hpp>
#include <EXPGL/Util/Positions2D.hpp>
#include <EXPGL/Input/InputXY.hpp>
#include <EXPGL/Input/InputKeyboard.hpp>
#include <EXPGL/Material/MaterialTexture2D.hpp>

int test_case(void)
{
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
    Window *window = context_manager->OpenWindow(0, 400, 400, NULL);
    Window *window2 = context_manager->OpenWindow(0, 400, 400, window);
    Window *window3 = context_manager->OpenWindow(0, 400, 400, window);
    
    std::vector<Window*> windows = { window, window2, window3 };
    
    RenderTarget *target = context_manager->CreateRenderTarget(windows);
    target->SetWindowOffsets(RenderTarget::HORIZONTAL);
    
    Renderer *renderer = new Renderer(target);
    renderer->SetClearColor(Colors::GREY_50);
    
    EXP::Rectangle *rectangle = resource_manager->CreateModel<EXP::Rectangle>(target);
    
    glm::vec2 rect_pos = Positions2D::CENTER;
    float step_amount = 0.005f;
    
    rectangle->SetUnits(Model::MIXED);
    rectangle->SetDimensions(50.0f, 50.0f);
    rectangle->SetPosition(rect_pos);
    
    EXP::MaterialSolid2D *mat = resource_manager->CreateMaterial<EXP::MaterialSolid2D>();
    mat->SetAlbedo(Colors::BLUE);
    rectangle->SetMaterial(mat);
    
    target->GetPrimaryWindow()->MakeCurrent();
    
#ifdef __APPLE__
    EXP::Texture2D *tex = resource_manager->GetTexture2D("/Users/Nick/Desktop/eg.png");
#else
	const char *pathstr = R"(C:\Users\changLab\Downloads\eg.png)";
	EXP::Texture2D *tex = resource_manager->GetTexture2D(pathstr);
#endif
	assert(tex);
    EXP::MaterialTexture2D *mat2 = resource_manager->CreateMaterial<EXP::MaterialTexture2D>(tex);
    rectangle->SetMaterial(mat2);
    
    target->GetPrimaryWindow()->Focus();
    
    InputXY mouse(target);
    InputKeyboard keyboard(target);
    
    while (true)
    {
        renderer->Draw(rectangle);
        if (keyboard.KeyDown(GLFW_KEY_ESCAPE))
        {
            context_manager->CloseWindow(window);
            break;
        }
        if (keyboard.KeyDown(GLFW_KEY_A))
        {
            rect_pos.x -= step_amount;
        }
        if (keyboard.KeyDown(GLFW_KEY_D))
        {
            rect_pos.x += step_amount;
        }
        if (keyboard.KeyDown(GLFW_KEY_W))
        {
            rect_pos.y -= step_amount;
        }
        if (keyboard.KeyDown(GLFW_KEY_S))
        {
            rect_pos.y += step_amount;
        }
        if (keyboard.KeyDown(GLFW_KEY_C))
        {
            rect_pos.x = 0.5f;
            rect_pos.y = 0.5f;
        }
        if (keyboard.KeyDown(GLFW_KEY_J))
        {
            rectangle->SetMaterial(mat2);
        }
        else if (keyboard.KeyDown(GLFW_KEY_K))
        {
            rectangle->SetMaterial(mat);
        }
        
        rectangle->SetPosition(rect_pos);
        
        glfwPollEvents();
    }
    
    delete context_manager;
    delete resource_manager;
    delete renderer;
    
    return 0;
}
