#include <iostream>
#include "Material.h"

#include "Shader.h"
#include "Texture.h"
#include "CubeMap.h"

Material::Material(const std::string& shader_path, const std::string& texture_path) {
    shader = new Shader(shader_path);
    texture = new Texture(texture_path);
}

Material::~Material() {
    delete shader;
    delete texture;
}

void Material::bind(Camera* camera, glm::mat4 modelVector, float ambient) const {
    shader->bind();
    texture->bind();
    this->setUniforms(camera, modelVector, ambient);
}

void Material::unbind() const {
    shader->unbind();
    texture->unbind();
}