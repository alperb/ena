#include "Application.h"

#include "materials/White.hpp"
#include "materials/Player.hpp"

#include "objects/Sphere.h"
#include "objects/Player.h"
#include "objects/Skybox.h"

int main() {

    Application* app = new Application("Sabanci Run", 800, 600);
    Scene* scene = new Scene();
    app->addScene(scene);

    Object* skybox = new Skybox();

    Object* object = new Sphere(glm::vec3(0.0f, -10.0f, -12.0f), 1.0f);
    object->setMaterial(new WhiteObject());

    Object* square = new Player(glm::vec3(0.0f, -10.0f, -3.0f));
    square->setMaterial(new PlayerMaterial());

    scene->setSkybox(skybox);
    scene->addObject(object);
    scene->addObject(square);

    app->setCurrentScene(scene);
    app->run();
    delete app;

    return 0;
}