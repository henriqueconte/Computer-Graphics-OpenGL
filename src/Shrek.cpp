#include "Shrek.h"

Shrek::Shrek()
{
    position = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
    collisionLayer = CollisionLayer();
}

Shrek::Shrek(glm::vec4 pos, CollisionLayer collisionLay)
{
    //dtor
    position = pos;
    collisionLayer = collisionLay;
}

void Shrek::move(std::vector<InvisibleWall> invisibleWallList, glm::vec4 movementDelta) {
    bool willCollide = false;
    glm::vec4 newPosition = position + 0.1f * movementDelta;
    collisionLayer.centerPosition = newPosition;

    for (auto wall : invisibleWallList) {
        // TODO: Implementar colisão do personagem com as paredes
            /*
         if (Box2SphereCollision(wall,collisionLayer)) {
             willCollide = true;
             break;
         }
         */
    }

    if (willCollide){
        collisionLayer.centerPosition = position;
    }
    else {
        position = newPosition;
    }
}
