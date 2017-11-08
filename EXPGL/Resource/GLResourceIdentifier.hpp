//
//  ResourceIdentifier.hpp
//  EXPGL
//
//  Created by Nick Fagan on 11/5/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#ifndef ResourceIdentifier_hpp
#define ResourceIdentifier_hpp

#include <stdio.h>
#include <string>

namespace EXP {
    class GLResourceIdentifier
    {
    public:
        GLResourceIdentifier();
        ~GLResourceIdentifier();
        
        void SetName(std::string name);
        void SetTag(std::string tag);
        void SetId(unsigned id);
        
        std::string GetName(void) const;
        std::string GetTag(void) const;
        unsigned GetId(void) const;
        
        void clone_from(const GLResourceIdentifier& source);
    private:
        unsigned id;
        std::string name;
        std::string tag;
    };
}

#endif /* ResourceIdentifier_hpp */
