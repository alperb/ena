#pragma once

#include "../Material.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class SkyboxMaterial : public Material {
public:
    SkyboxMaterial(const std::vector<std::string>& faces): Material("resources/shaders/skybox.hlsl", faces) {
    };
    ~SkyboxMaterial() = default;

    void setUniforms(Camera* camera, glm::mat4 modelVector) const override {
        shader->setUniformMat4f("u_Projection", camera->getProjectionMatrix());

        
        glm::mat4 view = glm::mat4(glm::mat3(camera->getViewMatrix()));
        shader->setUniformMat4f("u_View", view);
    };
};