#pragma once

#include "Mesh.h"
#include "Material.h"

class Object {
public:
    Object(std::string meshPath);
    ~Object();
    void draw(Camera* camera);
    void setMaterial(Material* material);

    virtual void onUpdate() = 0;
    virtual void move(glm::vec3 direction) = 0;

    bool isLightSource() const;

    glm::vec3 getPosition() const;
    glm::mat4 getModelMatrix() const;
protected:
    Material* material;
    Mesh* mesh;

    glm::vec3 position;

    bool lightSource = false;
};