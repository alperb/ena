#include "../Object.h"

class Sphere : public Object {
public:
    Sphere(glm::vec3 center, float radius, int slices, int stacks);
    ~Sphere() = default;

    void onUpdate() override;
    void move(glm::vec3 direction) override;
private:
    int speed = 1;
    void generatePositions();
    glm::vec3 center;
    float radius;
    int slices;
    int stacks;
};