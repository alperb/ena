#include "Renderer.h"

void Renderer::Render(const Scene& scene) {
    scene.draw();
}

void Renderer::Clear(){
    GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
    // GLCall(glClearColor(0.5f, 0.5f, 0.5f, 1.0f));
}