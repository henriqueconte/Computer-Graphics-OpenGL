#ifndef SHREK_H
#define SHREK_H
#include <glm/vec4.hpp>
#include <vector>
#include <iostream>
#include "CollisionLayer.h"
#include "InvisibleWall.h"
#include <GLFW/glfw3.h>
#include "Cow.h"
#include "Bunny.h"

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
        bool isAboveGrass;
        bool canMove;

        Shrek();
        Shrek(glm::vec4 pos, CollisionLayer collisionLay);

        void move(std::vector<InvisibleWall> invisibleWallList, glm::vec4 movementDelta);
        bool hasTouchedCow(Cow cow);
        bool hasTouchedBunny(Bunny bunny);
};

#endif // SHREK_H
