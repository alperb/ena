#include "Application.h"
#include "materials/White.hpp"
#include "materials/Player.hpp"
#include "objects/Sphere.h"
#include "objects/Square.h"


int main() {

    Application* app = new Application("Sabanci Run", 800, 600);
    Scene* scene = new Scene();
    app->addScene(scene);

    Object* object = new Sphere(glm::vec3(1.0f, 1.0f, -5.0f), 1.0f);
    object->setMaterial(new WhiteObject());

    Object* square = new Square(glm::vec3(0.0f, 0.0f, -5.0f));
    square->setMaterial(new Player());

    Camera* camera = new Camera(glm::vec3(0.0f, 5.0f, 20.0f), glm::vec3(0.0f, 0.0f, -2.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    scene->setCamera(camera);
    scene->addObject(object);
    scene->addObject(square);

    app->setCurrentScene(scene);
    app->run();
    delete app;

    return 0;
}