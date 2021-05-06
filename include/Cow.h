#ifndef COW_H
#define COW_H
#include <glm/vec4.hpp>
#include <vector>
#include <iostream>
#include "collisions.h"
#include <GLFW/glfw3.h>
#include <cmath>
#include <cstdio>
#include <cstdlib>


class Cow
{
    public:
        Cow();
        Cow(glm::vec4 pos, CollisionLayer collisionLay);
        glm::vec4 position;
        CollisionLayer collisionLayer;
        bool shouldMove;
        void bezierMove();
        glm::vec4 originalPosition;
};

#endif // COW_H
