#include <glm/glm.hpp>
#include "../Object.h"

class Square : public Object {
public:
    Square(glm::vec3 center);
    ~Square() = default;

    void onUpdate() override;
    void move(glm::vec3 direction) override;
private:
    glm::vec3 center;
};