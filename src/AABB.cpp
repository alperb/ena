#include "AABB.h"

AABB::AABB() {
    min = glm::vec3(0.0f, 0.0f, 0.0f);
    max = glm::vec3(0.0f, 0.0f, 0.0f);
}

AABB::~AABB() {
}

void AABB::setMin(glm::vec3 min) {
    this->min = min;
}

void AABB::setMax(glm::vec3 max) {
    this->max = max;
}

glm::vec3 AABB::getMin() const {
    return min;
}

glm::vec3 AABB::getMax() const {
    return max;
}

bool AABB::isColliding(AABB* other) const {
    if (max.x < other->getMin().x || min.x > other->getMax().x) {
        return false;
    }

    if (max.y < other->getMin().y || min.y > other->getMax().y) {
        return false;
    }

    if (max.z < other->getMin().z || min.z > other->getMax().z) {
        return false;
    }

    return true;
}

void AABB::updateBox(glm::mat4 modelMatrix) {
    glm::vec4 min4 = glm::vec4(min, 1.0f);
    glm::vec4 max4 = glm::vec4(max, 1.0f);

    min4 = modelMatrix * min4;
    max4 = modelMatrix * max4;

    min = glm::vec3(min4.x, min4.y, min4.z);
    max = glm::vec3(max4.x, max4.y, max4.z);
}