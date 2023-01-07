#pragma once

#include "../Material.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class RedSphere : public Material {
public:
    RedSphere(): Material("resources/shaders/RedSphere.hlsl", "") {};
    ~RedSphere() = default;

    void setUniforms(Camera* camera, glm::mat4 modelVector, float ambient) const override {
        shader->setUniformMat4f("u_MVP", camera->getMVP(modelVector));
        shader->setUniform4f("u_Color", 1.0f, 0.0f, 0.0f, 1.0f);
        shader->setUniformVec3f("u_viewPos", camera->getPosition());
    };
};