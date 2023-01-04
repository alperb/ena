#include "Scene.h"

Scene::Scene() {
    camera = new Camera(glm::vec3(0.0f, 10.0f, 10.0f), glm::vec3(0.0f, 0.0f, -2.0f), glm::vec3(0.0f, 1.0f, 0.0f));
}

Scene::~Scene() {
    for (Object* object : objects) {
        delete object;
    }

    delete camera;
}

void Scene::addObject(Object* object) {
    objects.push_back(object);
}

const std::vector<Object*> Scene::getObjects() const {
    return objects;
}

void Scene::setCamera(Camera* camera) {
    this->camera = camera;
}

Camera* Scene::getCamera() const {
    return camera;
}

void Scene::draw() const {
    glDepthMask(GL_FALSE);

    if (skybox != nullptr) {
        skybox->draw(camera);
    }

    glDepthMask(GL_TRUE);
    for (Object* object : objects) {
        object->draw(camera);
    }
}

void Scene::update() {
    for (Object* object : objects) {
        object->update();
    }
}

glm::vec3 Scene::getLightSourcePosition() const {
    for(Object* object : objects) {
        if (object->isLightSource()) {
            return object->getPosition();
        }
    }
    
    return glm::vec3(0.0f, 0.0f, 0.0f);
}

void Scene::setSkybox(Object* skybox) {
    this->skybox = skybox;
}