#pragma once

#include <glm/glm.hpp>

class Camera {
public:
    Camera(glm::vec3 position, glm::vec3 lookAt, glm::vec3 up);
    Camera();
    ~Camera();
private:
    glm::vec3 position;
    glm::vec3 lookAt;
    glm::vec3 up;
    glm::vec3 direction;
    glm::vec3 cameraRight;
    glm::vec3 cameraUp;

    void updateDirection();
};