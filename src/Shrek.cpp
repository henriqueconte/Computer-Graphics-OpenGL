#include "Shrek.h"

Shrek::Shrek()
{
    position = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
    shrekOriginalPosition = glm::vec4(8.0f, -1.0f, -12.0f, 1.0f);
    collisionLayer = CollisionLayer();
    isJumping = false;
    beforeJumpYPosition = 0.0f;
    jumpHeight = 2.0f;
    isGoingUp = false;
    bool isAboveGrass = false;
    canMove = true;
}

Shrek::Shrek(glm::vec4 pos, CollisionLayer collisionLay)
{
    position = pos;
    shrekOriginalPosition = glm::vec4(8.0f, -1.0f, -12.0f, 1.0f);
    collisionLayer = collisionLay;
    collisionLayer.centerPosition = position;
    isJumping = false;
    beforeJumpYPosition = 0.0f;
    jumpHeight = 2.0f;
    isGoingUp = false;
    bool isAboveGrass = false;
    canMove = true;
}


void Shrek::move(std::vector<InvisibleWall> invisibleWallList, glm::vec4 movementDelta) {
    if (canMove) {
        bool willCollide = false;
        glm::vec4 newPosition = position + 0.2f * movementDelta;
        collisionLayer.centerPosition = newPosition;
        isAboveGrass = false;

        // Checa se está em cima de uma grama ou lava
        for (auto wall: invisibleWallList) {
            if (collisionLayer.isCollidingWithLava(wall) && wall.isGrassFloor) {
                 isAboveGrass = true;
                 break;
            }
        }
        if (isAboveGrass == false) {
            // Checa se está colidindo com alguma parede
            for (auto wall : invisibleWallList) {
                if (collisionLayer.isCollidingWithWall(wall) && wall.isLavaFloor == false && wall.isGrassFloor == false) {
                    willCollide = true;
                    break;
                } else if (collisionLayer.isCollidingWithLava(wall) && wall.isLavaFloor) {
                    willCollide = true;
                    position = shrekOriginalPosition;
                    break;
                 }
            }
        }

        if (willCollide){
            collisionLayer.centerPosition = position;
        }
        else {
            position = newPosition;
        }
    }
}

// Checa se colidiu com vaca
bool Shrek::hasTouchedCow(Cow cow) {
    return collisionLayer.isCollidingWithCollisionLayer(cow.collisionLayer);
}

// Checa se tocou no coelho
bool Shrek::hasTouchedBunny(Bunny bunny) {
    return collisionLayer.isCollidingWithCollisionLayer(bunny.collisionLayer);
}
