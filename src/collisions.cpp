#include "collisions.h"

CollisionLayer::CollisionLayer()
{
    centerPosition = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
    collisionRadius = 0.0f;
}

CollisionLayer::CollisionLayer(glm::vec4 centerPos, float collisionRad)
{
    centerPosition = centerPos;
    collisionRadius = collisionRad;
}

// Colisão esfera -> cubo
bool CollisionLayer::isCollidingWithWall(InvisibleWall wall) {
    float x = std::max(wall.min.x, std::min(centerPosition.x, wall.max.x));
    float y = std::max(wall.min.y, std::min(centerPosition.y, wall.max.y));
    float z = std::max(wall.min.z, std::min(centerPosition.z, wall.max.z));

    float currentDistance = std::sqrt(
                            (x - centerPosition.x) * (x - centerPosition.x) +
                            (y - centerPosition.y) * (y - centerPosition.y) +
                            (z - centerPosition.z) * (z - centerPosition.z));

    return currentDistance < collisionRadius;
}

// Colisão ponto -> plano
bool CollisionLayer::isCollidingWithLava(InvisibleWall lavaFloor) {
    /*
    if (lavaFloor.isLavaFloor) {
        bool isInsideX = lavaFloor.min.x <= centerPosition.x && lavaFloor.max.x >= centerPosition.x;
        bool isBelowY = lavaFloor.max.y >= centerPosition.y;
        bool isInsideZ = lavaFloor.min.z <= centerPosition.z && lavaFloor.max.z >= centerPosition.z;
        return isInsideX && isBelowY && isInsideZ;
    } else if (lavaFloor.isGrassFloor) {
        bool isInsideX = lavaFloor.min.x <= centerPosition.x && lavaFloor.max.x >= centerPosition.x;
        bool isBelowY = lavaFloor.max.y >= centerPosition.y;
        bool isInsideZ = lavaFloor.min.z >= centerPosition.z && lavaFloor.max.z <= centerPosition.z;

        printf("\n isInsideX: ");
        std::cout << isInsideX;

        printf("\n isInsideY: ");
        std::cout << isBelowY;

        printf("\n isInsideZ: ");
        std::cout << isInsideZ;

         printf("\n min x: ");
         std::cout << lavaFloor.min.x;

         printf("\n max x: ");
         std::cout << lavaFloor.max.x;

         printf("\n min y: ");
         std::cout << lavaFloor.min.y;

         printf("\n max y: ");
         std::cout << lavaFloor.max.y;

         printf("\n min z: ");
         std::cout << lavaFloor.min.z;

         printf("\n min z: ");
         std::cout << lavaFloor.max.z;

        return isInsideX && isBelowY && isInsideZ;
    }
    */
    if (lavaFloor.isLavaFloor) {
        bool isInsideX = lavaFloor.min.x <= centerPosition.x && lavaFloor.max.x >= centerPosition.x;
        bool isBelowY = lavaFloor.max.y >= centerPosition.y;
        bool isInsideZ = lavaFloor.min.z <= centerPosition.z && lavaFloor.max.z >= centerPosition.z;
        return isInsideX && isBelowY && isInsideZ;
    } else if (lavaFloor.isGrassFloor) {
        bool isInsideX = lavaFloor.min.x <= centerPosition.x && lavaFloor.max.x >= centerPosition.x;
        //bool isBelowY = (lavaFloor.max.y + 1.0f) >= centerPosition.y;
        bool isBelowY = true;
        bool isInsideZ = lavaFloor.min.z <= centerPosition.z && lavaFloor.max.z >= centerPosition.z;
        /*
        printf("\n isInsideX: ");
        std::cout << isInsideX;

        printf("\n isInsideY: ");
        std::cout << isBelowY;

        printf("\n isInsideZ: ");
        std::cout << isInsideZ;

         printf("\n min x: ");
         std::cout << lavaFloor.min.x;

         printf("\n max x: ");
         std::cout << lavaFloor.max.x;

         printf("\n min y: ");
         std::cout << lavaFloor.min.y;

         printf("\n max y: ");
         std::cout << lavaFloor.max.y;

         printf("\n min z: ");
         std::cout << lavaFloor.min.z;

         printf("\n min z: ");
         std::cout << lavaFloor.max.z;

          printf("\n shrek x: ");
         std::cout << centerPosition.x;

         printf("\n shrek y: ");
         std::cout << centerPosition.y;

         printf("\n shrek z: ");
         std::cout << centerPosition.z;

         printf("\n \n");
         */
        return isInsideX && isBelowY && isInsideZ;
    }
}

// Colisão esfera -> esfera
bool CollisionLayer::isCollidingWithCollisionLayer(CollisionLayer collisionLayer) {
    float currentDistance = std::sqrt(
                            (centerPosition.x - collisionLayer.centerPosition.x) * (centerPosition.x - collisionLayer.centerPosition.x) +
                            (centerPosition.y - collisionLayer.centerPosition.y) * (centerPosition.y - collisionLayer.centerPosition.y) +
                            (centerPosition.z - collisionLayer.centerPosition.z) * (centerPosition.z - collisionLayer.centerPosition.z));
    return currentDistance < (collisionRadius + collisionLayer.collisionRadius);
}
