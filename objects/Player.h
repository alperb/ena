#include <glm/glm.hpp>
#include "../Object.h"

class Player : public Object {
public:
    Player(glm::vec3 center);
    ~Player() = default;

    void onUpdate() override;
    void move(glm::vec3 direction) override;
    void onCollision(Object* other) override;
    void onMoveEvent(Event event) override;
private:
    int currentPosition = 0;
    bool isMoving = false;
};