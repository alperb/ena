#pragma once
#include <vector>
#include <string>
#include <gl/glew.h>
#include <iostream>

#include "vendors/stb_image/stb_image.h"
#include "Texture.h"

class CubeMap : public Texture {
public:
    CubeMap(std::vector<std::string> faces);
    ~CubeMap();

    void load() override;
private:
    std::vector<std::string> faces;
};