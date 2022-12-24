#pragma once

#include <string>


class Texture {
public:
    Texture(const std::string& path);
    ~Texture();

    void bind(unsigned int slot = 0) const;
    void unbind() const;

    inline int getWidth() const { return m_width; }
    inline int getHeight() const { return m_height; }

    inline bool checkIfAvailable() const { return isAvailable; }
private:
    bool isAvailable;
    unsigned int m_rendererID;
    std::string m_filepath;
    unsigned char* m_localBuffer;
    int m_width, m_height, m_BPP;
};
