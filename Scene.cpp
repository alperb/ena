#include "Scene.h"

Scene::Scene() {
    camera = new Camera(glm::vec3(0.0f, 10.0f, 10.0f), glm::vec3(0.0f, 0.0f, -4.0f), glm::vec3(0.0f, 1.0f, 0.0f));
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

    // if (skybox != nullptr) {
    //     skybox->bind(camera, ambientStrength);
    // }

    glDepthMask(GL_TRUE);
    for (Object* object : objects) {
        object->draw(camera, ambientStrength);
        object->material->shader->setUniformVec3f("u_lightPos", lightPos);
    }
}

void Scene::moveSun(){
    if(isDay){
        lightPos.x += 0.01f;
        lightPos.y += 0.01f;
        if(lightPos.x >= 10.0f && lightPos.y >= 10.0f){
            isDay = false;
        }
    }else{
        lightPos.x -= 0.01f;
        lightPos.y -= 0.01f;
        if(lightPos.x <= -10.0f && lightPos.y <= -10.0f){
            isDay = true;
        }
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

void Scene::setSkybox(CubeMap* skybox) {
    this->skybox = skybox;
}

void Scene::popEnemy() {
    // count enemies in vector
    int enemyCount = 0;
    for (Object* object : objects) {
        if (object->getName() == "Enemy") {
            enemyCount++;
        }
    }
    if(enemyCount <= 7) return;

    for (int i = 0; i < objects.size(); i++) {
        if (objects[i]->getName() == "Enemy") {
            objects.erase(objects.begin() + i);
            break;
        }
    }
}