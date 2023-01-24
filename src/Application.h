#pragma once
#include <string>
#include <chrono>
#include <vector>
#include <iostream>

#include "GameManager.h"


class Application {
public:
    Application(const std::string& title, unsigned int width, unsigned int height);
    ~Application();
    void run();
    void addScene(Scene* scene);
    void setCurrentScene(Scene* scene);
    Scene* getCurrentScene();
    static void catchErr(int c, const char* m);

    void runUpdate();
private:
    void printFPS() const;
    GLFWwindow* window = nullptr;
    std::vector<Scene*> scenes;
    Scene* currentScene = nullptr;
    GameManager* gameManager = nullptr;
    std::string title;
    unsigned int width;
    unsigned int height;

    double lastRenderTime;
    double renderInterval = 1 / 60;
};