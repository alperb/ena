#include "Material.h"

#include "Shader.h"
#include "Texture.h"

Material::Material(const std::string& shader_path, const std::string& texture_path) {
    shader = new Shader(shader_path);
    texture = new Texture(texture_path);
}

Material::~Material() {
    delete shader;
    delete texture;
}

void Material::bind() const {
    shader->bind();
    texture->bind();
    this->setUniforms();
}

void Material::unbind() const {
    shader->unbind();
    texture->unbind();
}