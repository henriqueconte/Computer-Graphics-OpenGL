#include "Shrek.h"

Shrek::Shrek()
{
    position = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
    shrekOriginalPosition = glm::vec4(0.0f, -1.0f, -12.0f, 1.0f);
    collisionLayer = CollisionLayer();
    isJumping = false;
    beforeJumpYPosition = 0.0f;
    jumpHeight = 2.0f;
    isGoingUp = false;
}

Shrek::Shrek(glm::vec4 pos, CollisionLayer collisionLay)
{
    position = pos;
    shrekOriginalPosition = glm::vec4(0.0f, -1.0f, -12.0f, 1.0f);
    collisionLayer = collisionLay;
    isJumping = false;
    beforeJumpYPosition = 0.0f;
    jumpHeight = 2.0f;
    isGoingUp = false;
}


void Shrek::move(std::vector<InvisibleWall> invisibleWallList, glm::vec4 movementDelta) {
    bool willCollide = false;
    glm::vec4 newPosition = position + 0.5f * movementDelta;
    collisionLayer.centerPosition = newPosition;

    for (auto wall : invisibleWallList) {
         if (collisionLayer.isCollidingWithWall(wall) && wall.isLavaFloor == false) {
             willCollide = true;

             break;
         } else if(collisionLayer.isCollidingWithLava(wall) && wall.isLavaFloor) {
             willCollide = true;
             position = shrekOriginalPosition;
             break;
         }
    }

    if (willCollide){
        collisionLayer.centerPosition = position;
    }
    else {
        position = newPosition;
    }
}
