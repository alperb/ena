#pragma once
#include <string>
#include "Shader.h"
#include "Texture.h"

class Material {
public:
    Material(const std::string& shader_path, const std::string& texture_path);
    ~Material();
    void bind() const;
    void unbind() const;

    virtual void setUniforms() const = 0;
protected:
    Shader* shader;
    Texture* texture;
};