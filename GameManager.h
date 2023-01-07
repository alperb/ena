#pragma once
#include <chrono>
#include "Renderer.h"
#include <GLFW/glfw3.h>
#include <iostream>

class GameManager {
public:
    GameManager();
    ~GameManager();

    void update();
    void render();
    void checkCollisions();
    void processEvents();
    void pollEnemySpawn();

    void setScene(Scene* scene);

    static void onKeyPress(GLFWwindow* window, int key, int scancode, int action, int mods);
private:
    Scene* initialScene;
    void spawnMob();
    Scene* scene;
    std::chrono::time_point<std::chrono::steady_clock> lastSpawnTime;
};