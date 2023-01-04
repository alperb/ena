#include "GameManager.h"

GameManager::GameManager() {
}

GameManager::~GameManager() {
}

void GameManager::update() {
    scene->update();
    checkCollisions();
    processEvents();
}

void GameManager::render() {
    Renderer::Clear();
    Renderer::Render(*scene);
}

void GameManager::checkCollisions() {
    std::vector<Object*> objects = scene->getObjects();

    for (int i = 0; i < objects.size(); i++) {
        for (int j = 0; j < objects.size(); j++) {
            if(i == j) continue;

            if (objects[i]->getCollider()->isColliding(objects[j]->getCollider())) {
                objects[i]->onCollision(objects[j]);
                objects[j]->onCollision(objects[i]);
            }
        }
    }
}

void GameManager::processEvents() {

    for (Event event : EVENTS::Events) {
        for(Object* object : scene->getObjects()){
            if(event.action == MOVE_OBJECT){
                object->onMoveEvent(event);
            }
        }
    }
    if(EVENTS::Events.size() > 0) EVENTS::Events.clear();
}

void GameManager::setScene(Scene* scene) {
    this->scene = scene;
}

void GameManager::onKeyPress(GLFWwindow* window, int key, int scancode, int action, int mods){
    std::vector<Event> Events;

    if (key == GLFW_KEY_ESCAPE && glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(glfwGetCurrentContext(), true);
    }
    if (key == GLFW_KEY_RIGHT && glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_RIGHT) == GLFW_PRESS) {
        EVENTS::Events.push_back(Event(key, MOVE_OBJECT, RIGHT));
    }
    if (key == GLFW_KEY_LEFT && glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_LEFT) == GLFW_PRESS) {
        EVENTS::Events.push_back(Event(key, MOVE_OBJECT, LEFT));
    }
}