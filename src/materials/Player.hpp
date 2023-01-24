#pragma once

#include "../Material.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class PlayerMaterial : public Material {
public:
    PlayerMaterial(): Material("resources/shaders/player.hlsl", "") {
        ambient = glm::vec3(1.0f, 1.0f, 1.0f);
        diffuse = glm::vec3(0.9f, 0.9f, 0.5f);
        specular = glm::vec3(0.5f, 0.5f, 0.5f);
        shininess = 32.0f;
    };
    ~PlayerMaterial() = default;

    void setUniforms(Camera* camera, glm::mat4 modelVector, float ambientStrength) const override {
        shader->setUniformMat4f("u_MVP", camera->getMVP(modelVector));
        shader->setUniformMat4f("u_Model", modelVector);
        
        shader->setUniform4f("u_Color", ambient.r, ambient.g, ambient.b, 1.0f);
        shader->setUniform4f("u_specularColor", specular.r, specular.g, specular.b, 1.0f);
        shader->setUniform4f("u_diffuseColor", diffuse.r, diffuse.g, diffuse.b, 1.0f);
        shader->setUniform1f("u_shininess", shininess);
        shader->setUniform1f("u_ambientStrength", ambientStrength);

        shader->setUniformVec3f("u_viewPos", camera->getPosition());
    };
};