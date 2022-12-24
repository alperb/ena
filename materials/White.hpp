#pragma once

#include "../Material.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class WhiteObject : public Material {
public:
    WhiteObject(): Material("resources/shaders/basic.hlsl", "") {
        ambient = glm::vec3(0.7f, 0.2f, 0.6f);
        diffuse = glm::vec3(0.9f, 0.9f, 0.5f);
        specular = glm::vec3(0.5f, 0.5f, 0.5f);
        shininess = 32.0f;
    };
    ~WhiteObject() = default;

    void setUniforms(Camera* camera, glm::vec3 objectPosition) const override {
        glm::mat4 view = camera->getViewMatrix();
        glm::mat4 proj = camera->getProjectionMatrix();
        glm::mat4 t = proj * view * glm::translate(glm::mat4(1.0f), objectPosition);
        shader->setUniformMat4f("u_MVP", t);
        
        shader->setUniform4f("u_Color", ambient.r, ambient.g, ambient.b, 1.0f);
        shader->setUniform4f("u_specularColor", specular.r, specular.g, specular.b, 1.0f);
        shader->setUniform4f("u_diffuseColor", diffuse.r, diffuse.g, diffuse.b, 1.0f);
        shader->setUniform1f("u_shininess", shininess);

        shader->setUniformVec3f("u_lightPos", glm::vec3(3.0f, 1.0f, 0.0f));
        shader->setUniformVec3f("u_viewPos", camera->getPosition());
    };
};