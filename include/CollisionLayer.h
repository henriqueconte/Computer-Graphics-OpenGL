#ifndef COLLISIONLAYER_H
#define COLLISIONLAYER_H
#include <glm/vec4.hpp>
#include <cmath>
#include <iostream>
#include "InvisibleWall.h"

class CollisionLayer
{
    public:
        glm::vec4 centerPosition;
        float collisionRadius;

        CollisionLayer();
        CollisionLayer(glm::vec4 centerPos, float collisionRad);
        bool isCollidingWithWall(InvisibleWall wall);
        bool isCollidingWithLava(InvisibleWall lavaFloor);
};

#endif // COLLISIONLAYER_H
