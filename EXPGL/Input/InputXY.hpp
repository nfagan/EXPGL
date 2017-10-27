//
//  InputXY.hpp
//  EXPGL
//
//  Created by Nick Fagan on 10/24/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#ifndef InputXY_hpp
#define InputXY_hpp

#include <stdio.h>
#include "../Render/RenderTarget.hpp"
#include <glm/glm.hpp>

namespace EXP {
    class InputXY
    {
    public:
        InputXY(EXP::RenderTarget *target);
        virtual ~InputXY();
        
        virtual glm::vec2 GetCoordinates(void) const;
        virtual void UpdateCoordinates(void);
    protected:
        EXP::RenderTarget *target;
        glm::vec2 coordinates;
    };
}

#endif /* InputXY_hpp */
