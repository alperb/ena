#pragma once

#include "glm/glm.hpp"

class AABB {
public:
    AABB();
    ~AABB();

    void setMin(glm::vec3 min);
    void setMax(glm::vec3 max);

    glm::vec3 getMin() const;
    glm::vec3 getMax() const;

    bool isColliding(AABB* other) const;

    void updateBox(glm::mat4 modelMatrix);
private:
    glm::vec3 min;
    glm::vec3 max;
};