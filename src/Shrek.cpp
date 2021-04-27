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
}

Shrek::Shrek(glm::vec4 pos, CollisionLayer collisionLay)
{
    position = pos;
    shrekOriginalPosition = glm::vec4(8.0f, -1.0f, -12.0f, 1.0f);
    collisionLayer = collisionLay;
    isJumping = false;
    beforeJumpYPosition = 0.0f;
    jumpHeight = 2.0f;
    isGoingUp = false;
    bool isAboveGrass = false;
}


void Shrek::move(std::vector<InvisibleWall> invisibleWallList, glm::vec4 movementDelta) {
    bool willCollide = false;
    glm::vec4 newPosition = position + 0.2f * movementDelta;
    collisionLayer.centerPosition = newPosition;
    isAboveGrass = false;

    for (auto wall: invisibleWallList) {
        if (collisionLayer.isCollidingWithLava(wall) && wall.isGrassFloor) {
             printf("is colliding with grass");
             //willCollide = true;
             isAboveGrass = true;
             //position = shrekOriginalPosition;

            /*
                 printf("\n shrek x position: ");
                 std::cout << position.x;

                 printf("\n shrek y position: ");
                 std::cout << position.y;

                 printf("\n shrek z position: ");
                 std::cout << position.z;

                  printf("\n COLLISION x position: ");
                 std::cout << collisionLayer.centerPosition.x;

                 printf("\n COLLISION y position: ");
                 std::cout << collisionLayer.centerPosition.y;

                 printf("\n COLLISION z position: ");
                 std::cout << collisionLayer.centerPosition.z;

                 printf("\n min x: ");
                 std::cout << wall.min.x;

                 printf("\n max x: ");
                 std::cout << wall.max.x;

                 printf("\n min y: ");
                 std::cout << wall.min.y;

                 printf("\n max y: ");
                 std::cout << wall.max.y;

                 printf("\n min z: ");
                 std::cout << wall.min.z;

                 printf("\n max z: ");
                 std::cout << wall.max.z;
            */
             break;
        }
    }
    if (isAboveGrass == false) {
        for (auto wall : invisibleWallList) {
            if (collisionLayer.isCollidingWithWall(wall) && wall.isLavaFloor == false && wall.isGrassFloor == false) {
                willCollide = true;
                break;
            } else if (collisionLayer.isCollidingWithLava(wall) && wall.isLavaFloor) {
                 printf("is colliding with lava");
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
