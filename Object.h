#pragma once

#include "Mesh.h"
#include "Material.h"
#include "Collider.h"

#include "Event.h"

class Object {
public:
    Object(std::string meshPath);
    ~Object();
    void draw(Camera* camera);

    void setMaterial(Material* material);
    void createCollider();

    void update();
    virtual void init();
    virtual void move(glm::vec3 direction) = 0;
    virtual void onCollision(Object* other) = 0;

    bool isLightSource() const;
    glm::vec3 getPosition() const;
    glm::mat4 getModelMatrix() const;
    Collider* getCollider() const;
    void updateCollider();
    std::string getName() const { return name; }
    virtual void onMoveEvent(Event event) = 0;
protected:
    virtual void onUpdate() = 0;
    Material* material;
    Mesh* mesh;
    Collider* collider = nullptr;

    glm::vec3 position;
    float rotationAngle = 0.0f;
    glm::vec3 rotationAxis = glm::vec3(1.0f, 1.0f, 1.0f);

    bool lightSource = false;

    std::string name;
};