#include "Cow.h"

Cow::Cow(){
    position = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
    collisionLayer = CollisionLayer();
    shouldMove = false;
    originalPosition = position;
}

Cow::Cow(glm::vec4 pos, CollisionLayer collisionLay) {
    position = pos;
    collisionLayer = collisionLay;
    collisionLay.centerPosition = position;
    shouldMove = false;
    originalPosition = position;
}

// Implementação da curva de bezier aplicada à vaca
void Cow::bezierMove() {

    glm::vec4 p0 = glm::vec4(0.0f,0.0f,-0.1f, 1.0f);
    glm::vec4 p1 = glm::vec4(6.0f,6.0f, 0.4f, 1.0f);
    glm::vec4 p2 = glm::vec4(12.0f,3.0f,-0.4f, 1.0f);
    glm::vec4 p3 = glm::vec4(18.0f,0.0f, 0.1f, 1.0f);

    float t = (cos((float)glfwGetTime()) + 1.0f)/2.0f;

    float angle0 = pow(1 - t, 3);
    float angle1 = 3.0f * t * pow(1 - t, 2);
    float angle2 = 3.0f * pow(t, 2) * (1 - t);
    float angle3 = pow(t, 3);

    glm::vec4 position0 = angle0 * p0;
    glm::vec4 position1 = angle1 * p1;
    glm::vec4 position2 = angle2 * p2;
    glm::vec4 position3 = angle3 * p3;

    glm::vec4 point = position0 + position1 + position2 + position3;
    point.w = 0.0f;

    position = originalPosition + point;
}
