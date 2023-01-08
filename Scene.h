#pragma once

#include <vector>

#include "Object.h"
#include "CubeMap.h"
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
    void setSkybox(CubeMap* skybox);
    void draw() const;

    void popEnemy();
    void moveSun();
private:
    Camera* camera;
    std::vector<Object*> objects;
    CubeMap* skybox;
    float ambientStrength = 0.4f;
    glm::vec3 lightPos = glm::vec3(5.0f);

    bool isDay = true;
    bool isSunset = true;
    bool isSundown = false;

    friend class GameManager;
};