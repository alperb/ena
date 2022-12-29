#include "Logger.hpp"
#include "Object.h"


Object::Object(const std::string meshPath){
    mesh = new Mesh(meshPath);
    collider = new Collider(mesh->getPositions());
}

Object::~Object() {
}

void Object::draw(Camera* camera) {
    material->bind(camera, this->getModelMatrix());
    mesh->draw();
}

void Object::init(){
}

glm::mat4 Object::getModelMatrix() const {
    glm::mat4 translation = glm::translate(glm::mat4(1.0f), this->position);

    // 45 degree rotation around the y axis
    glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), this->rotationAngle, this->rotationAxis); //glm::rotate(glm::mat4(1.0f), glm::radians(45.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(1.0f));

    return translation * rotation * scale;
}

void Object::setMaterial(Material* material) {
    this->material = material;
}

bool Object::isLightSource() const {
    return lightSource;
}

glm::vec3 Object::getPosition() const {
    return position;
}

Collider* Object::getCollider() const {
    return collider;
}

void Object::move(glm::vec3 direction) {
    position += direction;
}

void Object::createCollider() {
    collider = new Collider(this->mesh->getPositions());
}

void Object::updateCollider() {
    collider->updateBox(this->mesh->getPositions(), this->getModelMatrix());
}

void Object::update() {
    this->onUpdate();
    this->updateCollider();
}

