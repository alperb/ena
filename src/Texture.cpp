#include <GL/glew.h>
#include "Texture.h"

#include "vendors/stb_image/stb_image.h"

Texture::Texture(const std::string& path): m_filepath(path), m_localBuffer(0), m_width(0), m_height(0), m_BPP(0) {
    load();
}

void Texture::load(){
    if(m_filepath != ""){
        isAvailable = true;

        stbi_set_flip_vertically_on_load(1);
        m_localBuffer = stbi_load(m_filepath.c_str(), &m_width, &m_height, &m_BPP, 4);

        GLCall(glGenTextures(1, &m_rendererID));
        GLCall(glBindTexture(GL_TEXTURE_2D, m_rendererID));

        GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
        GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
        GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
        GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));

        GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_localBuffer));
        GLCall(glBindTexture(GL_TEXTURE_2D, 0));

        if(m_localBuffer) {
            stbi_image_free(m_localBuffer);
        }
    }
    else{
        isAvailable = false;
    }
}

Texture::~Texture(){
    if(isAvailable) GLCall(glDeleteTextures(1, &m_rendererID));
}

void Texture::bind(unsigned int slot) const {
    if (!isAvailable) return;
    
    GLCall(glActiveTexture(GL_TEXTURE0 + slot));
    GLCall(glBindTexture(GL_TEXTURE_2D, m_rendererID));
}

void Texture::unbind() const {
    if (!isAvailable) return;

    GLCall(glBindTexture(GL_TEXTURE_2D, 0));
}