#include "GameManager.h"
#include "objects/Enemy.h"

GameManager::GameManager() {
    this->lastSpawnTime = std::chrono::steady_clock::now();
    
}

GameManager::~GameManager() {
}

void GameManager::update() {
    scene->update();
    checkCollisions();
    processEvents();
    pollEnemySpawn();

    // check for day/night cycle
    if(scene->isDay){
        if(scene->ambientStrength > 0.01f){
            scene->ambientStrength -= 0.001f;
        }
        else {
            scene->isDay = false;
            std::cout << "\nITS GETTING BRIGHTER\n\n";
        }
    }
    else {
        if(scene->ambientStrength < 0.4f){
            scene->ambientStrength += 0.001f;
        }
        else {
            scene->isDay = true;
            std::cout << "\nITS GETTING DARKER\n\n";
        }
    }
    scene->moveSun();
}

void GameManager::render() {
    Renderer::Clear();
    Renderer::Render(*scene);
}

void GameManager::pollEnemySpawn(){
    auto currentTime = std::chrono::steady_clock::now();
    auto timeSpan = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastSpawnTime);
    if (timeSpan.count() > 750) {
        lastSpawnTime = currentTime;
        spawnMob();
    }
}

void GameManager::spawnMob(){
    unsigned int laneInstances[3] = {0, 0, 0};
    for (Object* object : scene->getObjects()) {
        if (object->getName() == "Enemy") {
            laneInstances[((Enemy*)object)->getLane()]++;
        }
    }
    // get the lane with minimum enemies
    unsigned int minLane = 0;
    for (int i = 0; i < 3; i++) {
        if (laneInstances[i] < laneInstances[minLane]) {
            minLane = i;
        }
    }

    unsigned int lane = minLane;
    this->scene->addObject(new Enemy(lane));
    this->scene->popEnemy();
}

void GameManager::checkCollisions() {
    std::vector<Object*> objects = scene->getObjects();

    for (int i = 0; i < objects.size(); i++) {
        for (int j = 0; j < objects.size(); j++) {
            if(i == j) continue;

            if (objects[i]->getCollider()->isColliding(objects[j]->getCollider())) {
                objects[i]->onCollision(objects[j]);
                objects[j]->onCollision(objects[i]);

                if(objects[i]->getName() == "Player" && objects[j]->getName() == "Enemy"){
                    this->setScene(new Scene(*initialScene));
                    std::cout << std::endl << "GAME RESTARTED" << std::endl;
                }
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
    this->initialScene = new Scene(*scene);
    this->spawnMob();
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