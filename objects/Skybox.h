#include <glm/glm.hpp>
#include "../Object.h"

class Skybox : public Object {
public:
    Skybox();
    ~Skybox() = default;

    void onUpdate() override;
    void move(glm::vec3 direction) override;
    void onCollision(Object* other) override;
    void onMoveEvent(Event event) override;
private:
};