#include <glm/glm.hpp>
#include "../Object.h"

class Player : public Object {
public:
    Player(glm::vec3 center);
    ~Player() override;

    void onUpdate() override;
    void move(glm::vec3 direction) override;
    void onCollision(Object* other) override;
    void onMoveEvent(Event event) override;
private:
    int currentPosition = 1;
    glm::vec3 positions[3];
    glm::vec3 initialPosition;
    bool isMoving = false;
    glm::vec3 moveVector;
    float t = 0.0f;
    MOVE_DIRECTION direction;
};