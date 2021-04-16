#ifndef WALL_H
#define WALL_H
#include <glm/vec4.hpp>
#include <glm/vec3.hpp>

#include "InvisibleWall.h"

class Wall
{
    public:
        glm::vec4 position;
        glm::vec3 wallSize;
        InvisibleWall physicsBody;

        Wall();
        Wall(glm::vec4 pos, glm::vec3 wSize);
};

#endif // WALL_H
