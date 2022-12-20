#include "Renderer.h"
#include "util.h"

void Renderer::Render(const Scene& scene) {
    for (Object* object : scene.getObjects()) {
        object->draw();
    }
}

void Renderer::Clear(){
    GLCall(glClear(GL_COLOR_BUFFER_BIT));
}