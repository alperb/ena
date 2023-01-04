#pragma once
#include <string>
#include "Shader.h"
#include "Texture.h"
#include "Camera.h"

class Material {
public:
    ~Material();
    Material(const std::string& shader_path, const std::string& texture_path);
    Material(const std::string& shader_path, const std::vector<std::string>& texture_paths);
    void bind(Camera* camera, glm::mat4 modelVector) const;
    void unbind() const;

    virtual void setUniforms(Camera* camera, glm::mat4 modelVector) const = 0;

    glm::vec3 getAmbient() const { return ambient; }
    glm::vec3 getDiffuse() const { return diffuse; }
protected:
    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
    float shininess;
    
    Shader* shader;
    Texture* texture;
};