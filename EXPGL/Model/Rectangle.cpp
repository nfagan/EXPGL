//
//  Rectangle.cpp
//  EXPGL
//
//  Created by Nick Fagan on 10/22/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#include "Rectangle.hpp"

EXP::Rectangle::Rectangle() : EXP::Model(new Quad(), new MaterialSolid2D()) {
    owns_material = true;
}

EXP::Rectangle::Rectangle(EXP::Material *material) : EXP::Model(new Quad(), material)
{
    owns_material = false;
}

EXP::Rectangle::~Rectangle()
{
    delete mesh;
    if (owns_material)
    {
        delete material;
    }
}

EXP::Rect<float> EXP::Rectangle::GetPixelVertices(EXP::Rect<float> screen) const
{
    return get_pixel_vertices(screen);
}

EXP::Rect<float> EXP::Rectangle::GetPixelVertices(EXP::Rect<int> screen) const
{
    EXP::Rect<float> screen_ = static_cast<EXP::Rect<float>>(screen);
    return get_pixel_vertices(screen_);
}

EXP::Rect<float> EXP::Rectangle::get_pixel_vertices(EXP::Rect<float> screen) const
{
    glm::vec3 pos = get_units_position(screen);
    glm::vec3 scl = get_units_scale(screen);
    
    float left = pos.x - scl.x;
    float right = pos.x + scl.x;
    float top = pos.y - scl.y;
    float bottom = pos.y + scl.y;
    
    return EXP::Rect<float>(left, top, right, bottom);
}


