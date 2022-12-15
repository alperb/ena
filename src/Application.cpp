#include <iostream>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <string>
#include <sstream>

#include "Util.hpp"

#include "VertexBuffer.hpp"
#include "IndexBuffer.hpp"
#include "VertexArray.hpp"

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Sabanci Run", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    
    GLCall(glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE));

    /* Make the window's context current */
    GLCall(glfwMakeContextCurrent(window));
    GLCall(glfwSwapInterval(1));
    glewExperimental = GL_TRUE; 
    if(glewInit() != GLEW_OK) {
        std::cout << "Could not initalize OpenGL" << std::endl;
        return -1;
    }

    float positions[8] = {
        0.0f,  0.0f, // 0
        0.0f,  0.5f, // 1
        0.5f,  0.0f, // 2
        0.5f, 0.5f, // 3
    };

    unsigned int indices[6] = {
        0, 1, 2,
        2, 1, 3
    };
    
    std::cout << "a" << std::endl;
    VertexArray va;
    std::cout << "b" << std::endl;
    VertexBuffer vb(positions, 4 * 2 * sizeof(float));
    VertexBufferLayout layout;
    layout.push<float>(2);
    va.addBuffer(vb, layout);
    IndexBuffer ib(indices, 6);

    ShaderProgramSource src = parseShader("resources/shaders/basic.shader");
    unsigned int shader = createShader(src.VertexSource, src.FragmentSource);
    GLCall(glUseProgram(shader));

    GLCall(int location = glGetUniformLocation(shader, "u_Color"));
    ASSERT(location != -1);
    va.unbind();
    GLCall(glUseProgram(0));
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
    float r = 0.0f;
    float increment = 0.05f;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {


        /* Render here */
        GLCall(glClear(GL_COLOR_BUFFER_BIT));
        GLCall(glUseProgram(shader));
        GLCall(glUniform4f(location, r, 1.0f, 0.0f, 1.0f));

        va.bind();
        ib.bind();

        GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

        if(r > 1.0f) {
            increment = -0.05f;
        } else if(r < 0.0f) {
            increment = 0.05f;
        }

        r += increment;

        /* Swap front and back buffers */
        GLCall(glfwSwapBuffers(window));

        /* Poll for and process events */
        GLCall(glfwPollEvents());
    }

    GLCall(glDeleteProgram(shader));

    glfwTerminate();
    return 0;
}