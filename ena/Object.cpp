#include "Logger.hpp"
#include "Object.h"
#include "util.h"

Object::Object(const std::vector<float>& positions, const std::vector<unsigned int>& indices): positions(positions), indices(indices) {
    va = new VertexArray();

    vb = new VertexBuffer((void*)(positions.data()), positions.size() * sizeof(float));
    ib = new IndexBuffer((unsigned int*)(indices.data()), indices.size());
    vbl = new VertexBufferLayout();
    vbl->push<float>(3);
    vbl->push<float>(3);
    va->addBuffer(*vb, *vbl);

    va->unbind();
    vb->unbind();
    ib->unbind();
}

Object::~Object() {
    delete va;
    delete vb;
    delete vbl;
    delete ib;
    delete material;
}

void Object::draw() {
    va->bind();
    vb->bind();
    ib->bind();

    this->material->bind();

    GLCall(glDrawElements(GL_TRIANGLES, ib->getCount(), GL_UNSIGNED_INT, nullptr));
}

void Object::setMaterial(Material* material) {
    this->material = material;
}