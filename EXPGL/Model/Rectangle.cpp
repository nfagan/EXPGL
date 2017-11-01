//
//  Rectangle.cpp
//  EXPGL
//
//  Created by Nick Fagan on 10/22/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#include "Rectangle.hpp"

EXP::Rectangle::Rectangle() : EXP::Model2D(new Quad(), new MaterialSolid2D()) {
    width = 1.0f;
    height = 1.0f;
}

EXP::Rectangle::Rectangle(EXP::Material *material) : EXP::Model2D(new Quad(), material)
{
    width = 1.0f;
    height = 1.0f;
}

EXP::Rectangle::~Rectangle()
{
    delete mesh;
}

void EXP::Rectangle::SetDimensions(float width, float height)
{
    if (units == NORMALIZED || units == MIXED)
    {
        assert(width >= 0.0f && height >= 0.0f);
    }
    
    this->width = width;
    this->height = height;
}

glm::vec3 EXP::Rectangle::get_units_scale(Rect<float> screen) const
{
    glm::vec3 local_scale(width, height, 1.0f);
    if (units == NORMALIZED)
    {
        local_scale.x *= screen.get_width();
        local_scale.y *= screen.get_height();
    }
    return scale * local_scale;
}

glm::vec3 EXP::Rectangle::get_units_position(Rect<float> screen) const
{
    glm::vec3 pos(position.x, position.y, position.z);
    if (units == NORMALIZED || units == MIXED)
    {
        pos.x = (pos.x * screen.get_width()) + screen.get_left();
        pos.y = (pos.y * screen.get_height()) + screen.get_top();
    }
    return pos;
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

glm::mat4 EXP::Rectangle::GetTransformationMatrix(Rect<float> screen) const
{
    return get_transformation_matrix(screen);
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

glm::mat4 EXP::Rectangle::get_transformation_matrix(Rect<float> screen) const
{
    glm::mat4 transform(1.0f);
    transform = glm::translate(transform, get_units_position(screen));
    return glm::scale(transform, get_units_scale(screen));
}
