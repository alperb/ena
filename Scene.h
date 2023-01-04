#pragma once

#include <vector>

#include "Object.h"
#include "Camera.h"


class Scene {
public:
    Scene();
    ~Scene();

    void addObject(Object* object);
    const std::vector<Object*> getObjects() const;
    void setCamera(Camera* camera);
    Camera* getCamera() const;

    void update();

    glm::vec3 getLightSourcePosition() const;
    void setSkybox(Object* skybox);
    void draw() const;
private:
    Camera* camera;
    std::vector<Object*> objects;
    Object* skybox;
};