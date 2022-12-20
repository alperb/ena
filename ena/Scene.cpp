#include "Scene.h"

Scene::Scene() {
}

Scene::~Scene() {
    for (Object* object : objects) {
        delete object;
    }
}

void Scene::addObject(Object* object) {
    objects.push_back(object);
}

const std::vector<Object*> Scene::getObjects() const {
    return objects;
}