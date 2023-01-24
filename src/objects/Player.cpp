#include <math.h>
#include <iostream>
#include "Player.h"
#include "../materials/Player.hpp"

Player::Player(glm::vec3 center) : 
    Object("blender/square.obj") { 
        this->position = center;
        this->setName("Player");
        this->rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
        this->rotationAngle = 0.0f;
        this->initialPosition = center;
        this->setMaterial(new PlayerMaterial());

        // positions
        this->positions[0] = glm::vec3(center.x - 5.0f, center.y, center.z);
        this->positions[1] = glm::vec3(center.x, center.y, center.z);
        this->positions[2] = glm::vec3(center.x + 5.0f, center.y, center.z);
}

Player::~Player() {
    
}

void Player::move(glm::vec3 direction) {
}

void Player::onUpdate() {
    this->rotationAngle += 0.01f;

    if(this->isMoving){
        if(this->moveVector.x != 0.0f){
            this->position = this->positions[this->currentPosition] + this->moveVector * this->t;
            this->t += 0.1f;

            if(this->t >= 1.0f) {
                this->currentPosition += (this->direction == RIGHT ? 1 : -1);
                this->t = 0.0f;
                this->moveVector = glm::vec3(0);
                this->isMoving = false;
            }
        }
    }
}

void Player::onCollision(Object* other) {
    std::cout << "Player collided with " << other->getName() << std::endl;
}

void Player::onMoveEvent(Event event) {
    float thresholds[3] = {
        this->initialPosition.x - 5.0f,
        this->initialPosition.x,
        this->initialPosition.x + 5.0f
    };

    if(this->isMoving) return;

    glm::vec3 rightVector = glm::vec3(5.5f, 0.0f, 0.0f);
    glm::vec3 leftVector = glm::vec3(-5.5f, 0.0f, 0.0f);

    if(event.direction == RIGHT && this->currentPosition != 2){
        this->direction = RIGHT;
        this->moveVector = rightVector;
        this->t = 0.1f;
        this->isMoving = true;
        
    }
    else if(event.direction == LEFT && this->currentPosition != 0){
        this->direction = LEFT;
        this->moveVector = leftVector;
        this->t = 0.1f;
        this->isMoving = true;
    }
}