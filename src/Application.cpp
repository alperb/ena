#include <iostream>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <string>
#include <sstream>

#include "Util.cpp"

#include "VertexBuffer.hpp"
#include "IndexBuffer.hpp"


int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    // glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Sabanci Run", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    if(glewInit() != GLEW_OK) {
        std::cout << "Error!" << std::endl;
    }

    float positions[12] = {
        0.0f,  0.0f, // 0
        0.0f,  0.5f, // 1
        0.5f,  0.0f, // 2
        0.5f, 0.5f, // 3
    };

    unsigned int indices[6] = {
        0, 1, 2,
        2, 1, 3
    };

    unsigned int vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);


    VertexBuffer vb(positions, 4 * 2 * sizeof(float));

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

    IndexBuffer ib(indices, 6);

    ShaderProgramSource src = parseShader("resources/shaders/basic.shader");
    unsigned int shader = createShader(src.VertexSource, src.FragmentSource);
    glUseProgram(shader);

    int location = glGetUniformLocation(shader, "u_Color");
    assert(location != -1);
    float r = 0.0f;
    float increment = 0.05f;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {


        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(shader);
        glUniform4f(location, r, 1.0f, 0.0f, 1.0f);



        glBindVertexArray(vao);
        ib.bind();

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

        if(r > 1.0f) {
            increment = -0.05f;
        } else if(r < 0.0f) {
            increment = 0.05f;
        }

        r += increment;

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glDeleteProgram(shader);

    glfwTerminate();
    return 0;
}