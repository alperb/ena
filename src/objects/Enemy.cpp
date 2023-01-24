#include "Enemy.h"
#include "../materials/White.hpp"

Enemy::Enemy(unsigned int lane) : Sphere(glm::vec3(0.0f, -5.0f, -40.0f), 1.0f) {
    this->lane = lane;
    float d = 0.0f;
    if(lane == 0) {
        d = -5.0f;
    } else if(lane == 1) {
        d = 0.0f;
    } else if(lane == 2) {
        d = 5.0f;
    }
    this->position.x += d;
    this->center.x += d;

    this->setMaterial(new WhiteObject());
    this->setName("Enemy");
    this->speed = 25;
}

Enemy::~Enemy() {
    
}