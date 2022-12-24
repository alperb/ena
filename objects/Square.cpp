#include <math.h>
#include <iostream>
#include "Square.h"

Square::Square(glm::vec3 center) : 
    Object("blender/square.obj"), center(center) { 
}

void Square::move(glm::vec3 direction) {
}

void Square::onUpdate() {
    // move(moveVector);
    // std::cout << "x" << center.x << " y" << center.y << " z" << center.z << std::endl;
}