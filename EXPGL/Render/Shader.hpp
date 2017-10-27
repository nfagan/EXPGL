//
//  Shader.hpp
//  EXPGL
//
//  Created by Nick Fagan on 10/22/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#ifndef Shader_hpp
#define Shader_hpp

#include "../GL_HEADERS.h"
#include <stdio.h>
#include <string>

namespace EXP {
    
    class Shader
    {
    public:
        enum SHADER_TYPES
        {
            VERTEX = 0,
            FRAGMENT,
            GEOMETRY
        };
        
        Shader(void);
        virtual ~Shader(void);
        
        bool Attach(const char *filename, SHADER_TYPES shader_type);
        bool Link(void);
        void Start(void);
        void Stop(void);
        
        void SetMat4(const char* name, glm::mat4 value) const;
        void SetVec3(const char *name, glm::vec3 value) const;
        void SetInt(const char *name, int value) const;
        void SetBool(const char *name, bool value) const;
        void SetFloat(const char *name, float value) const;
    private:
        unsigned ID;
        
        unsigned shader_ids[3];
        unsigned n_shader_ids = 0;
        
        int check_link_errors(unsigned id);
        int check_compile_errors(unsigned id, std::string type);
    };
}

#endif /* Shader_hpp */
