#include <iostream>

#include <GL/glew.h>

#include "Renderer.h"
#include "util.h"
#include "Input.h"

#include "Application.h"
#include <GLFW/glfw3.h>

Application::Application(const std::string& title, unsigned int width, unsigned int height): title(title), width(width), height(height) {

    /* Initialize the library */
    if (glfwInit()) {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwSetErrorCallback(Application::catchErr);
        
        this->window = glfwCreateWindow(this->width, this->height, this->title.c_str(), NULL, NULL);
        if (!this->window)
        {
            std::cout << "Window is not created" << std::endl;
            glfwTerminate();
        }
        else {
            /* Make the window's context current */
            glfwMakeContextCurrent(this->window);
            glfwSwapInterval(1);

            glewExperimental = GL_TRUE;
            if(glewInit() != GLEW_OK) {
                std::cout << "Could not initalize OpenGL" << std::endl;
            }
        }
        GLCall(glEnable(GL_CULL_FACE));
        GLCall(glFrontFace(GL_CW));
        GLCall(glCullFace(GL_BACK));
        GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
        GLCall(glEnable(GL_BLEND));
        GLCall(glEnable(GL_DEPTH_TEST));
        
        glfwSetKeyCallback(window, Input::onKeyPress);
    }
}

Application::~Application() {
    glfwTerminate();
}

void Application::run() {
    while (!glfwWindowShouldClose(this->window))
    {
        /* Render here */
        Renderer::Clear();
        Renderer::Render(*(this->currentScene));
        /* Swap front and back buffers */
        GLCall(glfwSwapBuffers(window));

        /* Poll for and process events */
        runUpdate();

        printFPS();
    }
}

void Application::printFPS() const {
    static int frameCount = 0;
    static double previousSeconds = 0.0;
    double elapsedSeconds;
    double currentSeconds = glfwGetTime(); // returns number of seconds since glfwInit()

    elapsedSeconds = currentSeconds - previousSeconds;

    // limit text updates to 4 per second
    if (elapsedSeconds > 0.25) {
        previousSeconds = currentSeconds;
        double fps = (double)frameCount / elapsedSeconds;
        double msPerFrame = 1000.0 / fps;

        std::cout << msPerFrame << "ms/frame (" << fps << " FPS)" << std::endl;

        frameCount = 0;
    }

    frameCount++;
}

void Application::runUpdate(){
    currentScene->update();
    GLCall(glfwPollEvents());
}

void Application::catchErr(int c, const char* m) {
    std::cout << "CODE: " << c << std::endl;
    std::cout << "Error: " << m << std::endl;
}

void Application::addScene(Scene* scene) {
    this->scenes.push_back(scene);
}

void Application::setCurrentScene(Scene* scene) {
    this->currentScene = scene;
}

Scene* Application::getCurrentScene() {
    return this->currentScene;
}