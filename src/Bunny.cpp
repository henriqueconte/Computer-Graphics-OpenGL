#include "Bunny.h"

Bunny::Bunny() {
    position = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
    collisionLayer = CollisionLayer();
    hasBeenTouched = false;
    isHidden = true;
}

Bunny::Bunny(glm::vec4 pos, CollisionLayer collisionLay) {
    position = pos;
    collisionLayer = collisionLay;
    hasBeenTouched = false;
    isHidden = true;
}
