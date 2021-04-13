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
