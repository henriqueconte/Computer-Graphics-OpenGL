#include "Wall.h"

Wall::Wall(){
    position = glm::vec4(0.0f,0.0f,0.0f,1.0f);
    wallSize = glm::vec3(0.0f, 0.0f, 0.0f);
    physicsBody = InvisibleWall();
    bool shouldReverse = false;
}

Wall::Wall(glm::vec4 pos, glm::vec3 wSize, bool sReverse) {
    position = pos;
    //position.y = wSize.y / 2;
    wallSize = wSize;
    physicsBody = InvisibleWall(position, wSize.x, wSize.y, wSize.z);
    shouldReverse = sReverse;
}
