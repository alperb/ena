#include "Application.h"
#include "materials/test.hpp"

int main() {

    Application* app = new Application("Sabanci Run", 960, 540);
    Scene* scene = new Scene();
    app->addScene(scene);

    std::vector<float> positions = {
        -50.0f, -50.0f, 0.0f, 0.0f, 0.0f, 0.0f,
         50.0f, -50.0f, 0.0f, 1.0f, 0.0f, 0.0f,
         50.0f,  50.0f, 0.0f, 1.0f, 1.0f, 0.0f,
        -50.0f,  50.0f, 0.0f, 0.0f, 1.0f, 0.0f
    };

    std::vector<unsigned int> indices = {
        0, 1, 2,
        2, 3, 0
    };

    Object* object = new Object(positions, indices);
    object->setMaterial(new TestMaterial("resources/shaders/basic.shader", "resources/textures/cherno.png"));

    scene->addObject(object);
    app->setCurrentScene(scene);
    
    app->run();
    delete app;

    return 0;
}