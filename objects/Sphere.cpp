#include <math.h>
#include <glm/glm.hpp>
#include <iostream>
#include "Sphere.h"

Sphere::Sphere(glm::vec3 center, float radius) : 
    Object("blender/sphere.obj"), 
    center(center), radius(radius) { 
}

void Sphere::move(glm::vec3 direction) {
    center += direction;
    position = center;
}

void Sphere::onUpdate() {
    glm::vec3 moveVector = (float)speed * glm::vec3(0.005f, -0.005f, 0.005f);
    move(moveVector);
    // std::cout << "x" << center.x << " y" << center.y << " z" << center.z << std::endl;
}