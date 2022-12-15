#pragma once

#include <gl/glew.h>

class IndexBuffer {
public:
    IndexBuffer(const unsigned int* data, unsigned int count) : m_Count(count) {
        GLCall(glGenBuffers(1, &m_rendererID));
        GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_rendererID));
        GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), data, GL_STATIC_DRAW));
    }
    ~IndexBuffer() {

    }

    void bind() const {
        GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_rendererID));
    }
    void unbind() const {
        GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
    }
private:
    unsigned int m_rendererID;
    unsigned int m_Count;
};