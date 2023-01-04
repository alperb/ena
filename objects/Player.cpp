#include <math.h>
#include <iostream>
#include "Player.h"

Player::Player(glm::vec3 center) : 
    Object("blender/square.obj") { 
        this->position = center;
        this->name = "Player";
        this->rotationAxis = glm::vec3(1.0f, 1.0f, 1.0f);
        this->initialPosition = center;
}

Player::~Player() {
    
}

void Player::move(glm::vec3 direction) {
}

void Player::onUpdate() {
    this->rotationAngle += 0.01f;

    if(this->isMoving){
        glm::vec3 thresholds = {
            this->initialPosition.x - 5.0f,
            this->initialPosition.x,
            this->initialPosition.x + 5.0f
        };
        unsigned int index = this->currentPosition + (this->direction == RIGHT ? 1 : -1);
        if(index < 0 || index > 2) return;

        float th = thresholds[index];
        glm::vec3 target = this->initialPosition + glm::vec3(th, 0.0f, 0.0f);

        if(this->direction == RIGHT && this->position.x <= target.x){
            this->position += glm::vec3(0.4f, 0.0f, 0.0f);
        }
        else if(this->direction == LEFT && this->position.x >= target.x){
            this->position += glm::vec3(-0.4f, 0.0f, 0.0f);
        }
        else{
            this->currentPosition += (this->direction == RIGHT ? 1 : -1);
            this->isMoving = false;
        }
    }

    // move(moveVector);
    // std::cout << "x" << center.x << " y" << center.y << " z" << center.z << std::endl;
}

void Player::onCollision(Object* other) {
    std::cout << "Player collided with " << other->getName() << std::endl;
}

void Player::onMoveEvent(Event event) {
    std::cout << "Player received move event at position " << this->currentPosition << std::endl;
    if(event.direction == RIGHT && this->currentPosition != 2){
        this->direction = RIGHT;
        this->isMoving = true;
        // position = position + glm::vec3(5.0f, 0.0f, 0.0f);
        
    }
    else if(event.direction == LEFT && this->currentPosition != 0){
        this->direction = LEFT;
        this->isMoving = true;
        // position = position + glm::vec3(-5.0f, 0.0f, 0.0f);
    }
}