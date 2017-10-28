//
//  ProfileTimer.hpp
//  EXPGL
//
//  Created by Nick Fagan on 10/8/17.
//

#ifndef ProfileTimer_hpp
#define ProfileTimer_hpp

#include <stdio.h>
#include <limits>
#include <GLFW/glfw3.h>

class GLFrameTimer {
    
public:
    GLFrameTimer();
    void Update();
    void Summarize();
    float GetLatestDelta();
    float GetLatestDeltaSeconds();
    
private:
    float current_frame = 0.0f;
    float delta_frame = 0.0f;
    float last_frame = 0.0f;
    
    double min_frame = std::numeric_limits<double>::max();
    double max_frame = -std::numeric_limits<double>::min();
    double mean_frame = 0.0;
    
    unsigned long iteration = 0;
};

#endif /* ProfileTimer_hpp */


