//
//  multiple_windows.cpp
//  EXPGL
//
//  Created by Nick Fagan on 10/26/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#include <iostream>
#include <EXPGL.hpp>

int test_case(void)
{
    using namespace EXP;
    
    GLContextManager *context_manager = new GLContextManager();
    GLResourceManager *resource_manager = new GLResourceManager();
    
    if (!context_manager->DidInitialize())
    {
        fprintf(stderr, "Error initializing");
        delete resource_manager;
        delete context_manager;
        return EXIT_FAILURE;
    }
    
    std::vector<Window*> windows;
    
//    windows.push_back(context_manager->OpenWindow(0, 400, 400, NULL));
    windows.push_back(context_manager->OpenWindow(0, 400, 400, NULL));
    windows.push_back(context_manager->OpenWindow(0, 400, 400, windows[0]));
//    windows.push_back(context_manager->OpenWindow(0, 400, 400, windows[0]));
//    windows.push_back(context_manager->OpenWindow(0, 400, 400, windows[0]));
    
    RenderTarget *target = context_manager->CreateRenderTarget(windows);
    target->SetWindowOffsets(RenderTarget::HORIZONTAL);
    
    Renderer *renderer = new Renderer(target);
    renderer->SetClearColor(Colors::GREY_50);
    
    EXP::Rectangle *rectangle = resource_manager->CreateModel<EXP::Rectangle>(target);
    
    glm::vec2 rect_pos = Positions2D::CENTER;
    float step_amount = 0.005f;
    
    rectangle->SetUnits(Model::MIXED);
    rectangle->SetDimensions(100.0f, 200.0f);
    rectangle->SetPosition(rect_pos);
    
    EXP::MaterialSolid2D *mat = resource_manager->CreateMaterial<EXP::MaterialSolid2D>();
    mat->SetAlbedo(Colors::BLUE);
    rectangle->SetMaterial(mat);
    
//    target->GetPrimaryWindow()->MakeCurrent();
    
#ifdef __APPLE__
    Texture *tex = resource_manager->GetTexture<Texture>("/Users/Nick/Desktop/eg.png");
#else
	const char *pathstr = R"(C:\Users\changLab\Downloads\eg.png)";
	Texture *tex = resource_manager->GetTexture<Texture>(pathstr);
#endif
	assert(tex);
    EXP::MaterialTexture2D *mat2 = resource_manager->CreateMaterial<EXP::MaterialTexture2D>(tex);
    
    EXP::Image *image = resource_manager->CreateModel<EXP::Image>(target, mat2);
    image->SetPosition(rect_pos);
    image->SetUnits(Model::MIXED);
    image->SetScale(100.0f);
    
    rectangle->SetMaterial(mat2);
    
    target->GetPrimaryWindow()->Focus();
    
    InputXY mouse(target);
    InputKeyboard keyboard(target);
    
    while (true)
    {
        renderer->Queue(image);
//        renderer->Queue(rectangle);
        renderer->Draw();
        if (keyboard.KeyDown(GLFW_KEY_ESCAPE))
        {
            context_manager->CloseWindow(windows[0]);
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
        if (keyboard.KeyDown(GLFW_KEY_V))
        {
            rect_pos.x = 0.333333f;
            rect_pos.y = 0.5f;
        }
        if (keyboard.KeyDown(GLFW_KEY_B))
        {
            rect_pos.x = 0.666666f;
            rect_pos.y = 0.5f;
        }
        if (keyboard.KeyDown(GLFW_KEY_J))
        {
            rectangle->SetMaterial(mat2);
            image->SetScale(100.0f);
        }
        else if (keyboard.KeyDown(GLFW_KEY_K))
        {
            rectangle->SetMaterial(mat);
            image->SetScale(200.0f);
        }
        
        image->SetPosition(rect_pos);
        
        mouse.UpdateCoordinates();
        mouse.PrintCoordinates();
        
        glfwPollEvents();
    }
    
    delete context_manager;
    delete resource_manager;
    delete renderer;
    
    return 0;
}
