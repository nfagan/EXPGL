//
//  MaterialSolid2D.hpp
//  EXPGL
//
//  Created by Nick Fagan on 10/26/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#ifndef MaterialSolid2D_hpp
#define MaterialSolid2D_hpp

#include <stdio.h>
#include "Material.hpp"
#include <glm/glm.hpp>
#include <EXPUtil/thread/spinlock.hpp>

namespace EXP {
    class MaterialSolid2D : public EXP::Material
    {
    public:
        MaterialSolid2D();
        ~MaterialSolid2D() = default;
        
        void SetAlbedo(glm::vec3 albedo);
        void Configure(EXP::Shader *shader);

		glm::vec3 GetAlbedo(void);
    protected:
		spinlock albedo_lock;
		glm::vec3 albedo;
    };
}

#endif /* MaterialSolid2D_hpp */
