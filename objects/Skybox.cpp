#include <math.h>
#include <iostream>
#include "Skybox.h"
#include "../materials/SkyboxMaterial.hpp"

Skybox::Skybox(): 
    Object("blender/square.obj") { 
        this->position = glm::vec3(0.0f);
        this->name = "Skybox";
        this->scaleFactor = glm::vec3(50.0f);
        std::vector<std::string> faces = { "right.jpg", "left.jpg", "top.jpg", "bottom.jpg", "front.jpg", "back.jpg" };
        this->material = new SkyboxMaterial(faces);
        this->collider->setCollidable(false);
}

void Skybox::move(glm::vec3 direction) {
}

void Skybox::onUpdate() {
}

void Skybox::onCollision(Object* other) {
}

void Skybox::onMoveEvent(Event event) {
}