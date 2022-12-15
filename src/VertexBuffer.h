#pragma once
#include <gl/glew.h>

class VertexBuffer {
public:
    VertexBuffer() = default;
    VertexBuffer(const void* data, unsigned int size);
    ~VertexBuffer();

    void bind() const;
    void unbind() const;
private:
    unsigned int m_rendererID;
};