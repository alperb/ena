#include <vector>
#include "VertexBufferLayout.h"

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
