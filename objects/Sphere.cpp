#include <math.h>
#include <glm/glm.hpp>
#include <iostream>
#include "Sphere.h"

Sphere::Sphere(glm::vec3 center, float radius) : 
    Object("blender/sphere.obj"), 
    center(center), radius(radius) { 
        this->position = center;
        this->name = "Sphere";
        this->speed = 5;
        this->rotationAngle = glm::radians(45.0f);
        this->rotationAxis = glm::vec3(-1.0f, 0.0f, 0.0f);
}

Sphere::~Sphere() {
    
}

void Sphere::move(glm::vec3 direction) {
    center += direction;
    position = center;
}

void Sphere::onUpdate() {
    this->rotationAngle += glm::radians(5.0f);
    glm::vec3 moveVector = (float)speed * glm::vec3(0.0f, 0.0f, 0.01f);
    move(moveVector);
    // std::cout << "x" << center.x << " y" << center.y << " z" << center.z << std::endl;
}

void Sphere::onCollision(Object* other) {
    // std::cout << "Sphere collided with " << other << std::endl;
}

void Sphere::onMoveEvent(Event event) {
    // std::cout << "Sphere moved" << std::endl;
}