#pragma once

#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexBufferLayout.h"
#include "Material.h"

class Object {
public:
    Object(const std::vector<float>& positions, const std::vector<unsigned int>& indices);
    ~Object();
    void draw();
    void setMaterial(Material* material);
protected:
    VertexArray* va;
    VertexBuffer* vb;
    VertexBufferLayout* vbl;
    IndexBuffer* ib;
    Material* material;

    std::vector<float> positions;
    std::vector<unsigned int> indices;
};