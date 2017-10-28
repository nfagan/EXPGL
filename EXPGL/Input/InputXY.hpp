//
//  InputXY.hpp
//  EXPGL
//
//  Created by Nick Fagan on 10/24/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#ifndef InputXY_hpp
#define InputXY_hpp

#define EXPGL__INPUTXY__DO_ATOMIC

#include <stdio.h>
#include "../Render/RenderTarget.hpp"
#include <glm/glm.hpp>
#include <atomic>

namespace EXP {
    class InputXY
    {
    public:
        InputXY(EXP::RenderTarget *target);
        virtual ~InputXY();
        
        virtual glm::vec2 GetCoordinates(void) const;
        virtual void UpdateCoordinates(void);
        virtual void PrintCoordinates(void) const;
    protected:
        EXP::RenderTarget *target;
#ifdef EXPGL__INPUTXY__DO_ATOMIC
        std::atomic<float> x;
        std::atomic<float> y;
#else
        float x;
        float y;
#endif
    };
}

#endif /* InputXY_hpp */
