#include "InvisibleWall.h"

InvisibleWall::InvisibleWall()
{
    min = glm::vec4(0.0f,0.0f,0.0f,1.0f);
    max = glm::vec4(0.0f,0.0f,0.0f,1.0f);
    bool isLavaFloor = false;
    bool isGrassFloor = false;
}

InvisibleWall::InvisibleWall(glm::vec4 c, float w, float h, float d)
{
    min = c - glm::vec4(w/2.0f,h/2.0f,d/2.0f,0.0f);
    max = c + glm::vec4(w/2.0f,h/2.0f,d/2.0f,0.0f);

    if (min.z > max.z) {
        float aux = min.z;
        min.z = max.z;
        max.z = aux;
    }
    bool isLavaFloor = false;
    bool isGrassFloor = false;
}
