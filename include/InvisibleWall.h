#ifndef INVISIBLEWALL_H
#define INVISIBLEWALL_H
#include <glm/vec4.hpp>

class InvisibleWall
{
    public:
        glm::vec4 min;
        glm::vec4 max;
        bool isLavaFloor;
        bool isGrassFloor;

        // Constructor
        InvisibleWall();
        InvisibleWall(glm::vec4 c, float w, float h, float d);
};

#endif // INVISIBLEWALL_H
