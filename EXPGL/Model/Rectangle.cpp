//
//  Rectangle.cpp
//  EXPGL
//
//  Created by Nick Fagan on 10/22/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#include "Rectangle.hpp"

EXP::Rectangle::Rectangle() : EXP::Shape2D(new Quad()) {
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
    glm::vec3 scale(width, height, 1.0f);
    if (units == NORMALIZED)
    {
        scale.x *= screen.get_width();
        scale.y *= screen.get_height();
    }
    return scale;
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

glm::mat4 EXP::Rectangle::GetTransformationMatrix(Rect<float> window, Rect<float> screen) const
{
    return get_transformation_matrix(window, screen);
}

glm::mat4 EXP::Rectangle::get_transformation_matrix(Rect<float> window, Rect<float> screen) const
{
    glm::mat4 transform(1.0f);
    transform = glm::translate(transform, get_units_position(screen));
    return glm::scale(transform, get_units_scale(screen));
}
