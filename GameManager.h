#pragma once
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

    void setScene(Scene* scene);

    static void onKeyPress(GLFWwindow* window, int key, int scancode, int action, int mods);
private:
    Scene* scene;
};