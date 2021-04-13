#ifndef COLLISIONLAYER_H
#define COLLISIONLAYER_H
#include <glm/vec4.hpp>

class CollisionLayer
{
    public:
        glm::vec4 centerPosition;
        float collisionRadius;

        CollisionLayer();
        CollisionLayer(glm::vec4 centerPos, float collisionRad);
};

#endif // COLLISIONLAYER_H
