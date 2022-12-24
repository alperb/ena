#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
public:
    Camera(glm::vec3 position, glm::vec3 lookAt, glm::vec3 up);
    Camera();
    ~Camera();

    void setPosition(glm::vec3 position);
    void setLookAt(glm::vec3 lookAt);
    void setUp(glm::vec3 up);

    glm::vec3 getPosition() const;
    glm::vec3 getLookAt() const;
    glm::vec3 getUp() const;

    glm::mat4 getProjectionMatrix() const;
    glm::mat4 getViewMatrix() const;

    glm::mat4 getMVP(glm::mat4 modelVector) const;

    void setScreenSize(int width, int height);

    glm::vec3 getLocalPosition(glm::vec3 worldPosition) const;
private:
    glm::vec3 position;
    glm::vec3 lookAt;
    glm::vec3 up;
    glm::vec3 direction;
    glm::vec3 cameraRight;
    glm::vec3 cameraUp;

    int screenWidth;
    int screenHeight;

    void updateDirection();
};