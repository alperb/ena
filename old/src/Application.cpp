#include <iostream>

// #define GLFW_INCLUDE_NONE
// #define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <string>
#include <sstream>

#include "util.h"

#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "Renderer.h"
#include "Texture.h"
#include "Input.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>





void catcherr(int c, const char* m) {
    std::cout << "CODE: " << c << std::endl;
    std::cout << "Error: " << m << std::endl;
}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit()) return -1;
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwSetErrorCallback(catcherr);
    window = glfwCreateWindow(960, 540, "Sabanci Run", NULL, NULL);
    if (!window)
    {
        std::cout << "a" << std::endl;
        glfwTerminate();
        return -1;
    }

    int major, minor, rev;

    glfwGetVersion(&major, &minor, &rev);

    std::cout <<  "OpenGL version recieved:" <<  major <<  minor << rev << std::endl;
    

    

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    glewExperimental = GL_TRUE;
    if(glewInit() != GLEW_OK) {
        std::cout << "Could not initalize OpenGL" << std::endl;
        return -1;
    }

    
    // std::cout << glfwGetVersionString() << std::endl;
    float positions[] = {
        -50.0f,  -50.0f, 0.0f, 0.0f, // 0
        50.0f,  -50.0f, 1.0f, 0.0f, // 1
        50.0f,  50.0f, 1.0f, 1.0f,// 2
        -50.0f,  50.0f, 0.0f, 1.0f// 3
    };

    unsigned int indices[6] = {
        0, 1, 2,
        2, 3, 0
    };

    GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
    GLCall(glEnable(GL_BLEND));

    glfwSetKeyCallback(window, Input::onKeyPress);




    VertexArray va;
    VertexBuffer vb(positions, 4 * 4 * sizeof(float));
    
    VertexBufferLayout layout;
    layout.push<float>(2);
    layout.push<float>(2);
    va.addBuffer(vb, layout);
    
    IndexBuffer ib(indices, 6);

    glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));
    glm::mat4 proj = glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f);
    
    Shader shader("resources/shaders/basic.shader");
    shader.bind();

    Texture texture("resources/textures/cherno.png");
    texture.bind();
    shader.setUniform1i("u_Texture", 0);
    

    va.unbind();
    shader.unbind();
    vb.unbind();
    ib.unbind();

    float r = 0.0f;
    float increment = 0.05f;

    Renderer renderer;
    
    glm::vec3 translation(200, 200, 0);
    

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        renderer.clear();


        va.bind();
        shader.bind();
        vb.bind();
        ib.bind();

        shader.setUniformMat4f("u_MVP", proj * view * glm::translate(glm::mat4(1.0f), translation));
        renderer.draw(va, ib, shader);

        /* Swap front and back buffers */
        GLCall(glfwSwapBuffers(window));

        /* Poll for and process events */
        GLCall(glfwPollEvents());
    }

    glfwTerminate();
    return 0;
}