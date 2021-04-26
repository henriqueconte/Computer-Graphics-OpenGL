#include "CollisionLayer.h"

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

    float distance = std::sqrt(
                            (x - centerPosition.x) * (x - centerPosition.x)
                            +
                            (y - centerPosition.y) * (y - centerPosition.y)
                            +
                            (z - centerPosition.z) * (z - centerPosition.z)
    );

    return distance < collisionRadius;
}

// Colisão ponto -> plano
bool CollisionLayer::isCollidingWithLava(InvisibleWall lavaFloor) {
    bool isInsideX = lavaFloor.min.x <= centerPosition.x && lavaFloor.max.x >= centerPosition.x;
    bool isBelowY = lavaFloor.max.y >= centerPosition.y;
    bool isInsideZ = lavaFloor.min.z <= centerPosition.z && lavaFloor.max.z >= centerPosition.z;
    return isInsideX && isBelowY && isInsideZ;
}
