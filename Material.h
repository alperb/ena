#pragma once
#include <string>
#include "Shader.h"
#include "Texture.h"
#include "Camera.h"

class Material {
public:
    Material(const std::string& shader_path, const std::string& texture_path);
    ~Material();
    void bind(Camera* camera, glm::vec3 objectPosition) const;
    void unbind() const;

    virtual void setUniforms(Camera* camera, glm::vec3 objectPosition) const = 0;

    glm::vec3 getAmbient() const { return ambient; }
    glm::vec3 getDiffuse() const { return diffuse; }
protected:
    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
    Shader* shader;
    Texture* texture;
};