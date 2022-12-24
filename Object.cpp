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
    material->bind(camera, this->position);
    mesh->draw();
}

// void Object::draw(Camera* camera) {
//     va->bind();
//     vb->bind();
//     ib->bind();
//     material->bind(camera, this->position);

//     GLCall(glDrawElements(GL_TRIANGLES, ib->getCount(), GL_UNSIGNED_INT, nullptr));
// }

void Object::setMaterial(Material* material) {
    this->material = material;
}

bool Object::isLightSource() const {
    return lightSource;
}

glm::vec3 Object::getPosition() const {
    return position;
}

