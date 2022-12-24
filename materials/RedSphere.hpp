#pragma once

#include "../Material.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class RedSphere : public Material {
public:
    RedSphere(): Material("resources/shaders/RedSphere.hlsl", "") {};
    ~RedSphere() = default;

    void setUniforms(Camera* camera, glm::vec3 objectPosition) const override {
        glm::mat4 view = camera->getViewMatrix();
        glm::mat4 proj = camera->getProjectionMatrix();
        glm::mat4 t = proj * view * glm::translate(glm::mat4(1.0f), objectPosition);
        shader->setUniformMat4f("u_MVP", t);
        shader->setUniform4f("u_Color", 1.0f, 0.0f, 0.0f, 1.0f);
        shader->setUniformVec3f("u_lightPos", glm::vec3(0.0f, 0.0f, 0.0f));
        shader->setUniformVec3f("u_viewPos", camera->getPosition());
    };
};