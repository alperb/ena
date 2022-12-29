#include "Application.h"


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

        gameManager = new GameManager();
        
        glfwSetKeyCallback(window, GameManager::onKeyPress);
    }
}

Application::~Application() {
    glfwTerminate();
}

void Application::run() {
    double now = glfwGetTime();
    while (!glfwWindowShouldClose(this->window))
    {
        auto renderDiff = now - lastRenderTime;
        if(renderDiff > this->renderInterval) {
            lastRenderTime += renderInterval;

            /* Render here */
            gameManager->render();
            printFPS();
        }
        /* Swap front and back buffers */
        GLCall(glfwSwapBuffers(window));
        
        runUpdate();
    }
}

void Application::printFPS() const {
    static int frameCount = 0;
    static double lastTime = glfwGetTime();
    double currentTime = glfwGetTime();
    frameCount++;
    if (currentTime - lastTime >= 1.0) {
        std::cout << "FPS: " << frameCount << std::endl;
        frameCount = 0;
        lastTime += 1.0;
    }
}

void Application::runUpdate(){
    gameManager->update();
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
    gameManager->setScene(scene);
}

Scene* Application::getCurrentScene() {
    return this->currentScene;
}