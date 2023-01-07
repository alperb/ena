#pragma once
#include <vector>
#include <string>
#include <gl/glew.h>
#include <iostream>

#include "vendors/stb_image/stb_image.h"
#include "Shader.h"

class CubeMap {
public:
    CubeMap(std::vector<std::string> faces);
    CubeMap() = default;
    ~CubeMap() = default;

    void load();
    void bind() const;
    void unbind() const;
protected:
    unsigned int textureID;
    std::vector<std::string> faces;
    Shader* shader;
};