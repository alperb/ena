#pragma once
#include "AABB.h"
#include <vector>

class Collider {
public:
    Collider(std::vector<float> positions);
    ~Collider();

    bool isColliding(Collider* other);
    void updateBox(std::vector<float> positions, glm::mat4 modelMatrix);
private:
    AABB* aabb;

    void computeBoundingBox(std::vector<float> positions);
};