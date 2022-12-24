#include "Logger.hpp"
#include "Object.h"
#include "Util.h"


Object::Object(const std::string meshPath){
    mesh = new Mesh(meshPath);
}

// Object::Object(const std::vector<float>& positions, const std::vector<unsigned int>& indices): positions(positions), indices(indices) {
//     va = new VertexArray();

//     vb = new VertexBuffer((void*)(positions.data()), positions.size() * sizeof(float));
//     ib = new IndexBuffer((unsigned int*)(indices.data()), indices.size());
//     vbl = new VertexBufferLayout();
//     vbl->push<float>(3);
//     vbl->push<float>(3);
//     va->addBuffer(*vb, *vbl);

//     va->unbind();
//     vb->unbind();
//     ib->unbind();
// }

Object::~Object() {
}

void Object::draw(Camera* camera) {
    material->bind(camera, this->getModelMatrix());
    mesh->draw();
}

glm::mat4 Object::getModelMatrix() const {
    // 45 degree rotation around the y axis
    glm::mat4 rotation = glm::translate(glm::mat4(1.0f), position) * glm::rotate(glm::mat4(1.0f), glm::radians(45.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    // scale the object to its original size
    glm::mat4 model = glm::scale(rotation, glm::vec3(1.0f));
    return model;
}

void Object::setMaterial(Material* material) {
    this->material = material;
}

bool Object::isLightSource() const {
    return lightSource;
}

glm::vec3 Object::getPosition() const {
    return position;
}

