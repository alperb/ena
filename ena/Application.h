#pragma once
#include <string>
#include "Scene.h"
#include <vector>
#include <GLFW/glfw3.h>

class Application {
public:
    Application(const std::string& title, unsigned int width, unsigned int height);
    ~Application();
    void run();
    void addScene(Scene* scene);
    void setCurrentScene(Scene* scene);
    Scene* getCurrentScene();
    static void catchErr(int c, const char* m);
private:
    GLFWwindow* window = nullptr;
    std::vector<Scene*> scenes;
    Scene* currentScene = nullptr;
    std::string title;
    unsigned int width;
    unsigned int height;
};