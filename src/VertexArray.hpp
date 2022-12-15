#pragma once

#include "VertexBuffer.hpp"
#include "VertexBufferLayout.hpp"

class VertexArray {
public:
    VertexArray(){
        GLCall(glGenVertexArrays(1, &m_rendererID));
    }
    ~VertexArray(){
        GLCall(glDeleteVertexArrays(1, &m_rendererID));
    }

    void addBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout){
        this->bind();

        vb.bind();
        const auto& elements = layout.getElements();
        unsigned int offset = 0;

        for(unsigned int i = 0; i < elements.size(); i++) {
            const auto& element = elements[i];

            GLCall(glEnableVertexAttribArray(i));
            GLCall(glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.getStride(), (const void*)offset));
            offset += element.count * VertexBufferElement::getSizeOfType(element.type);
        }
    }

    void bind() const {
        GLCall(glBindVertexArray(m_rendererID));
    }

    void unbind() const {
        GLCall(glBindVertexArray(0));
    }
private:
    unsigned int m_rendererID;
};