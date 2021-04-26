#include "InvisibleWall.h"

InvisibleWall::InvisibleWall()
{
    min = glm::vec4(0.0f,0.0f,0.0f,1.0f);
    max = glm::vec4(0.0f,0.0f,0.0f,1.0f);
    bool isLavaFloor = false;
}

InvisibleWall::InvisibleWall(glm::vec4 c, float w, float h, float d)
{
    min = c - glm::vec4(w/2.0f,h/2.0f,d/2.0f,0.0f);
    max = c + glm::vec4(w/2.0f,h/2.0f,d/2.0f,0.0f);
    bool isLavaFloor = false;
}
