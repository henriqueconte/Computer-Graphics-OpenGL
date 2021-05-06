#ifndef BUNNY_H
#define BUNNY_H
#include <glm/vec4.hpp>
#include <vector>
#include <iostream>
#include "collisions.h"
#include <GLFW/glfw3.h>
#include <cmath>
#include <cstdio>
#include <cstdlib>

class Bunny
{
    public:
        Bunny();
        Bunny(glm::vec4 pos, CollisionLayer collisionLay);
        glm::vec4 position;
        CollisionLayer collisionLayer;
        bool hasBeenTouched;
        bool isHidden;
};

#endif // BUNNY_H
