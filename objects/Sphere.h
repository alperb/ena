#include "../Object.h"

class Sphere : public Object {
public:
    Sphere(glm::vec3 center, float radius);
    ~Sphere() override;

    void onUpdate() override;
    void move(glm::vec3 direction) override;
    void onMoveEvent(Event event) override;
    void onCollision(Object* other) override;
private:
    int speed = 1;
    glm::vec3 center;
    float radius;
};