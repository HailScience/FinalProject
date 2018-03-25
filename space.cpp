#include <iostream>
#include "space.hpp"

Space::Space(int position, char color)
{
    this->position = position;
    this->color = color;
    top = NULL;
    bottom = NULL;
    left = NULL;
    right = NULL;
}