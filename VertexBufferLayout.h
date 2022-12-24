#pragma once
#include <GL/glew.h>
#include <vector>

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
    VertexBufferLayout(): m_Stride(0) {}

    template<typename T>
    void push(unsigned int count);
    inline unsigned int getStride() const { return m_Stride; }

    inline const std::vector<VertexBufferElement> getElements() const { return m_Elements; }
private:
    std::vector<VertexBufferElement> m_Elements;
    unsigned int m_Stride;
};
