#ifndef SHREK_H
#define SHREK_H
#include <glm/vec4.hpp>
#include <vector>
#include "CollisionLayer.h"
#include "InvisibleWall.h"

class Shrek
{
    public:
        glm::vec4 position;
        CollisionLayer collisionLayer;

        Shrek();
        Shrek(glm::vec4 pos, CollisionLayer collisionLay);

        void move(std::vector<InvisibleWall> invisibleWallList, glm::vec4 movementDelta);
};

#endif // SHREK_H
