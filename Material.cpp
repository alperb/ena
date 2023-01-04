#include <iostream>
#include "Material.h"

#include "Shader.h"
#include "Texture.h"
#include "CubeMap.h"

Material::Material(const std::string& shader_path, const std::string& texture_path) {
    shader = new Shader(shader_path);
    texture = new Texture(texture_path);
}

// its a cubemap
Material::Material(const std::string& shader_path, const std::vector<std::string>& texture_paths) {
    shader = new Shader(shader_path);
    texture = new CubeMap(texture_paths);
}

Material::~Material() {
    delete shader;
    delete texture;
}

void Material::bind(Camera* camera, glm::mat4 modelVector) const {
    shader->bind();
    texture->bind();
    this->setUniforms(camera, modelVector);
}

void Material::unbind() const {
    shader->unbind();
    texture->unbind();
}