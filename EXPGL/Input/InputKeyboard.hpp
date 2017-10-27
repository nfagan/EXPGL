//
//  InputKeyboard.hpp
//  EXPGL
//
//  Created by Nick Fagan on 10/26/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#ifndef InputKeyboard_hpp
#define InputKeyboard_hpp

#include <stdio.h>
#include "../Render/RenderTarget.hpp"

namespace EXP {
    class InputKeyboard
    {
    public:
        InputKeyboard(EXP::RenderTarget *target);
        ~InputKeyboard();
        
        bool KeyDown(int id);
    private:
        EXP::RenderTarget *target;
    };
}

#endif /* InputKeyboard_hpp */
