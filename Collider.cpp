#include "Collider.h"

Collider::Collider(std::vector<float> positions) {
    aabb = new AABB();
    computeBoundingBox(positions);
}

Collider::~Collider() {
    delete aabb;
}

void Collider::computeBoundingBox(std::vector<float> positions){
    glm::vec3 min = glm::vec3(positions[0], positions[1], positions[2]);
    glm::vec3 max = glm::vec3(positions[0], positions[1], positions[2]);

    for (int i = 0; i < positions.size(); i += 3) {
        if (positions[i] < min.x) {
            min.x = positions[i];
        }
        if (positions[i] > max.x) {
            max.x = positions[i];
        }

        if (positions[i + 1] < min.y) {
            min.y = positions[i + 1];
        }
        if (positions[i + 1] > max.y) {
            max.y = positions[i + 1];
        }

        if (positions[i + 2] < min.z) {
            min.z = positions[i + 2];
        }
        if (positions[i + 2] > max.z) {
            max.z = positions[i + 2];
        }
    }

    aabb->setMin(min);
    aabb->setMax(max);
}

bool Collider::isColliding(Collider* other) {
    if (!isCollidable || !other->isCollidable) {
        return false;
    }
    return aabb->isColliding(other->aabb);
}

void Collider::updateBox(std::vector<float> positions, glm::mat4 modelMatrix) {
    // std::vector<float> computedPositions;
    // for (int i = 0; i < positions.size(); i += 3) {
    //     glm::vec4 position = glm::vec4(positions[i], positions[i + 1], positions[i + 2], 1.0f);
    //     position = modelMatrix * position;
    //     computedPositions.push_back(position.x);
    //     computedPositions.push_back(position.y);
    //     computedPositions.push_back(position.z);
    // }
    computeBoundingBox(positions);
    aabb->updateBox(modelMatrix);
}

void Collider::setCollidable(bool collidable) {
    isCollidable = collidable;
}