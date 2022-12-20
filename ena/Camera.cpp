#include "Camera.h"

Camera::Camera(glm::vec3 position, glm::vec3 lookAt, glm::vec3 up): position(position), lookAt(lookAt), up(up) {
    updateDirection();
}

Camera::Camera(): position(glm::vec3(0, 0, 0)), lookAt(glm::vec3(0, 0, 0)), up(glm::vec3(0, 0, 0)) {
    updateDirection();
}

Camera::~Camera() {
}

void Camera::updateDirection() {
    direction = glm::normalize(lookAt - position);
    cameraRight = glm::normalize(glm::cross(up, direction));
    cameraUp = glm::normalize(glm::cross(direction, cameraRight));
}
