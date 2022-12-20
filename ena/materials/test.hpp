#pragma once

#include "../Material.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class TestMaterial : public Material {
public:
    TestMaterial(const std::string& shader_path, const std::string& texture_path): Material(shader_path, texture_path) {};
    ~TestMaterial() = default;

    void setUniforms() const override {
        glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));
        glm::mat4 proj = glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f);
        glm::vec3 translation(200, 200, 0);
        shader->setUniformMat4f("u_MVP", proj * view * glm::translate(glm::mat4(1.0f), translation));
        shader->setUniform1i("u_Texture", 0);
    };
};