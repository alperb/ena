#include "Sphere.h"

class Enemy : public Sphere {
public:
    Enemy(unsigned int lane);
    ~Enemy() override;

    unsigned int getLane() { return lane;}
private:
    unsigned int lane;
};