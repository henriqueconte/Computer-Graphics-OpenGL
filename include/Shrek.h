#ifndef SHREK_H
#define SHREK_H
#include <glm/vec4.hpp>
#include <vector>
#include <iostream>
#include "CollisionLayer.h"
#include "InvisibleWall.h"
#include <GLFW/glfw3.h>

class Shrek
{
    public:
        glm::vec4 position;
        glm::vec4 shrekOriginalPosition;
        CollisionLayer collisionLayer;
        bool isJumping;
        float beforeJumpYPosition;
        float jumpHeight;
        bool isGoingUp;

        Shrek();
        Shrek(glm::vec4 pos, CollisionLayer collisionLay);

        void move(std::vector<InvisibleWall> invisibleWallList, glm::vec4 movementDelta);
};

#endif // SHREK_H
