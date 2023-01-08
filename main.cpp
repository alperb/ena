#include "Application.h"

#include "CubeMap.h"

#include "objects/Enemy.h"
#include "objects/Player.h"

int main() {

    Application* app = new Application("Sabanci Run", 800, 600);
    Scene* scene = new Scene();
    app->addScene(scene);

    CubeMap* skybox = new CubeMap({ 
        "resources/textures/skybox/right.jpg", 
        "resources/textures/skybox/left.jpg", 
        "resources/textures/skybox/top.jpg", 
        "resources/textures/skybox/bottom.jpg", 
        "resources/textures/skybox/front.jpg", 
        "resources/textures/skybox/back.jpg" 
    });
    Object* square = new Player(glm::vec3(0.0f, -5.0f, -4.0f));

    scene->setSkybox(skybox);
    scene->addObject(square);

    app->setCurrentScene(scene);
    app->run();
    delete app;

    return 0;
}