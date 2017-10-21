//
//  EXPGL.cpp
//  EXPGL
//
//  Created by Nick Fagan on 10/20/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#include <iostream>
#include "EXPGL.hpp"
#include "EXPGLPriv.hpp"

void EXPGL::HelloWorld(const char * s)
{
    EXPGLPriv *theObj = new EXPGLPriv;
    theObj->HelloWorldPriv(s);
    delete theObj;
};

void EXPGLPriv::HelloWorldPriv(const char * s) 
{
    std::cout << s << std::endl;
};

