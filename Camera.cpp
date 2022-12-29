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

void Camera::setPosition(glm::vec3 position) {
    this->position = position;
    updateDirection();
}

void Camera::setLookAt(glm::vec3 lookAt) {
    this->lookAt = lookAt;
    updateDirection();
}

void Camera::setUp(glm::vec3 up) {
    this->up = up;
    updateDirection();
}

glm::vec3 Camera::getPosition() const {
    return position;
}

glm::vec3 Camera::getLookAt() const {
    return lookAt;
}

glm::vec3 Camera::getUp() const {
    return up;
}

glm::mat4 Camera::getProjectionMatrix() const {
    return glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
}

glm::mat4 Camera::getViewMatrix() const {
    return glm::lookAt(position, position + direction, up);
}

glm::mat4 Camera::getMVP(glm::mat4 modelVector) const {
    return getProjectionMatrix() * getViewMatrix() * modelVector;
}

glm::vec3 Camera::getLocalPosition(glm::vec3 worldPosition) const {
    glm::mat4 viewMatrix = getViewMatrix();
    glm::mat4 inverseViewMatrix = glm::inverse(viewMatrix);
    glm::vec4 localPosition = inverseViewMatrix * glm::vec4(worldPosition, 1.0f);
    return glm::vec3(localPosition);
}
