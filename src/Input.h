#pragma once

#include <GLFW/glfw3.h>

class Input {
public:
    static void onKeyPress(GLFWwindow* window, int key, int scancode, int action, int mods);
};