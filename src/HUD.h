#pragma once
#include <map>
#include <gl/glew.h>
#include <iostream>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <ft2build.h>
#include FT_FREETYPE_H

#include "Util.h"
#include "Shader.h"


class HUD {
public:
    HUD();
    ~HUD();
    void render(std::string text, float x, float y, float scale, glm::vec3 color);
private:
    struct Character {
        unsigned int TextureID;  // ID handle of the glyph texture
        glm::ivec2   Size;       // Size of glyph
        glm::ivec2   Bearing;    // Offset from baseline to left/top of glyph
        unsigned int Advance;    // Offset to advance to next glyph
    };
    FT_Library ft;
    FT_Face face;
    std::map<char, Character> Characters;

    Shader* shader;
    unsigned int VAO, VBO;
};