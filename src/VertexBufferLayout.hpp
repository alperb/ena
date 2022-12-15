#pragma once
#include <vector>
#include <GL/glew.h>

struct VertexBufferElement {
    unsigned int type;
    unsigned int count;
    unsigned char normalized;

    VertexBufferElement(unsigned int type, unsigned int count, unsigned char normalized) : type(type), count(count), normalized(normalized) {}

    static unsigned int getSizeOfType(unsigned int type){
        switch(type) {
            case GL_FLOAT:          return 4;
            case GL_UNSIGNED_INT:   return 4;
            case GL_UNSIGNED_BYTE:  return 1;
        }
        return 0;
    }
};

class VertexBufferLayout {
public:
    VertexBufferLayout(){}

    template<typename T>
    void push(unsigned int count);

    inline unsigned int getStride() const { return m_Stride; }

    inline const std::vector<VertexBufferElement> getElements() const { return m_Elements; }
private:
    std::vector<VertexBufferElement> m_Elements;
    unsigned int m_Stride;
};

template<typename T>
void VertexBufferLayout::push(unsigned int count) {
}

template<>
void VertexBufferLayout::push<float>(unsigned int count) {
    m_Elements.push_back(VertexBufferElement( GL_FLOAT, count, GL_FALSE ));
    m_Stride += count * VertexBufferElement::getSizeOfType(GL_FLOAT);
}

template<>
void VertexBufferLayout::push<unsigned int>(unsigned int count) {
    m_Elements.push_back(VertexBufferElement( GL_UNSIGNED_INT, count, GL_FALSE ));
    m_Stride += count * VertexBufferElement::getSizeOfType(GL_UNSIGNED_INT);
}

template<>
void VertexBufferLayout::push<unsigned char>(unsigned int count) {
    m_Elements.push_back(VertexBufferElement(GL_UNSIGNED_BYTE, count, GL_TRUE));
    m_Stride += count * VertexBufferElement::getSizeOfType(GL_UNSIGNED_BYTE);
}
