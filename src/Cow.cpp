#include "Cow.h"

Cow::Cow(){
    position = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
    collisionLayer = CollisionLayer();
}

Cow::Cow(glm::vec4 pos, CollisionLayer collisionLay) {
    position = pos;
    collisionLayer = collisionLay;
}
