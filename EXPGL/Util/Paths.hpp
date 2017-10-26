//
//  Paths.hpp
//  EXPGL
//
//  Created by Nick Fagan on 10/22/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#ifndef Paths_hpp
#define Paths_hpp

#include <stdio.h>
#include <string>

namespace EXP {
    namespace PATHS {
        static const std::string get_shader_dir()
        {
#ifdef _WIN32
			std::string path = R"(C:\Users\changLab\Repositories\cpp\EXPGL\EXPGL\Shaders\)";
			return path;
#elif __APPLE__
            return std::string("/Volumes/external/code/changlab/tasks/exp/EXPGL/EXPGL/Shaders/");
#endif
        }
        static const std::string get_stimulus_2d_shader_name()
        {
            return get_shader_dir() + std::string("stimulus_2d");
        }
    }
}

#endif /* Paths_hpp */
