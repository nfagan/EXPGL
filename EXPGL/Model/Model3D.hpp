//
//  Model3D.hpp
//  EXPGL
//
//  Created by Nick Fagan on 10/27/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#ifndef Model3D_hpp
#define Model3D_hpp

#include <stdio.h>

#include <stdio.h>
#include "Model.hpp"
#include "../Material/Material.hpp"
#include "../Util/Rect.hpp"

namespace EXP {
    class Model3D : public EXP::Model
    {
    public:
        Model3D(EXP::Mesh *mesh, EXP::Material *material);
        virtual ~Model3D();
        virtual glm::mat4 GetTransformationMatrix(Rect<float> window, Rect<float> screen) const;
    };
}

#endif /* Model3D_hpp */
