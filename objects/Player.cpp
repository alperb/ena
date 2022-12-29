#include <math.h>
#include <iostream>
#include "Player.h"

Player::Player(glm::vec3 center) : 
    Object("blender/square.obj") { 
        this->position = center;
        this->name = "Player";
}

void Player::move(glm::vec3 direction) {
}

void Player::onUpdate() {
    // move(moveVector);
    // std::cout << "x" << center.x << " y" << center.y << " z" << center.z << std::endl;
}

void Player::onCollision(Object* other) {
    std::cout << "Player collided with " << other->getName() << std::endl;
}

void Player::onMoveEvent(Event event) {
    std::cout << "Player moved" << std::endl;
    position = position + glm::vec3(0.5f, 0.0f, 0.0f);
}