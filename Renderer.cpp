#include "Renderer.h"
#include "Util.h"

void Renderer::Render(const Scene& scene) {
    // set screen with and height to the camera
    // scene.getCamera()->setScreenSize(width, height);

    for (Object* object : scene.getObjects()) {
        object->draw(scene.getCamera());
    }
}

void Renderer::Clear(){
    GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
    // GLCall(glClearColor(0.5f, 0.5f, 0.5f, 1.0f));
}