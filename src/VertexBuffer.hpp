#pragma once

#include <gl/glew.h>

class VertexBuffer {
public:
    VertexBuffer(const void* data, unsigned int size) {
        glGenBuffers(1, &m_rendererID);
        glBindBuffer(GL_ARRAY_BUFFER, m_rendererID);
        glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    }
    ~VertexBuffer() {

    }

    void bind() const {
        glBindBuffer(GL_ARRAY_BUFFER, m_rendererID);
    }
    void unbind() const {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
private:
    unsigned int m_rendererID;
};