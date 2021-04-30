#ifndef COW_H
#define COW_H
#include <glm/vec4.hpp>
#include <vector>
#include <iostream>
#include "CollisionLayer.h"
#include <GLFW/glfw3.h>

class Cow
{
    public:
        Cow();
        Cow(glm::vec4 pos, CollisionLayer collisionLay);
        glm::vec4 position;
        CollisionLayer collisionLayer;
};

#endif // COW_H
