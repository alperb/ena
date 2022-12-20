#pragma once

#include <iostream>

#include "IndexBuffer.h"
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "Renderer.h"

class Object {
public:
    Object(const void* positions, unsigned int indices, const std::string& shader) : shader(shader), indices(indices), positions(positions) {}
    ~Object() = default;
    void render() const { renderer.draw(*va, *ibo, *vbo); }
private:
    void setup(){
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

        va.bind();
        shader.bind();
        vb.bind();
        ib.bind();
    }
    // void setupVAO(){
    //     va = new VertexArray();
    //     va->bind();
    //     va->addBuffer(*vbo, 0);
    //     va->unbind();
    // }
    // void setupVBO(){
    //     std::cout << sizeof(positions) << std::endl;
    //     vbo = new VertexBuffer(positions, sizeof(positions));
    //     vbo->bind();
    // }
    // void setupIBO(){
    //     ibo = new IndexBuffer(indices, sizeof(indices) / sizeof(unsigned int));
    // }
    // void setupRenderer(){
    //     renderer = new Renderer();
    // }

    // VertexArray* va;
    // VertexBuffer* vbo;
    // IndexBuffer* ibo;
    Renderer renderer;

    const void* positions;
    unsigned int* indices;
    Shader shader;
};