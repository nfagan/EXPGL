//
//  ProfileTimer.cpp
//  EXPGL
//
//  Created by Nick Fagan on 10/8/17.
//

#include "GLFrameTimer.hpp"

GLFrameTimer::GLFrameTimer() {}

void GLFrameTimer::Update() {
    current_frame = glfwGetTime();
    delta_frame = current_frame - last_frame;
    last_frame = current_frame;
    
    double iterationd = (double)iteration;
    mean_frame = (mean_frame * iterationd + delta_frame) / (iterationd+1.0f);
    
    iteration++;
    
    if (delta_frame > max_frame) max_frame = delta_frame;
    if (delta_frame < min_frame) min_frame = delta_frame;
}

float GLFrameTimer::GetLatestDelta() {
    return delta_frame;
}

float GLFrameTimer::GetLatestDeltaSeconds() {
    return delta_frame * 1000.0f;
}

void GLFrameTimer::Summarize() {
    printf("\n\n%lu Iterations", iteration);
    printf("\n\n%0.4f (fps) Mean frame rate", 1.0f/mean_frame);
    printf("\n\n%0.4f (ms) Mean frame time", mean_frame*1000.0f);
    printf("\n\n%0.4f (ms) Min frame time", min_frame*1000.0f);
    printf("\n\n%0.4f (ms) Max frame time", max_frame*1000.0f);
    printf("\n\n\n");
}

