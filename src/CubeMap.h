#pragma once
#include <vector>
#include <string>
#include <gl/glew.h>
#include <iostream>

#include "vendors/stb_image/stb_image.h"
#include "Shader.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Camera.h"

class CubeMap {
public:
    CubeMap(std::vector<std::string> faces);
    CubeMap() = default;
    ~CubeMap() = default;

    void load();
    void bind() const;
    void unbind() const;
    void draw(Camera* camera) const;
protected:

    void initObject();

    unsigned int textureID;
    std::vector<std::string> faces;
    Shader* shader;

    VertexArray* vao;
    VertexBuffer* vbo;
    IndexBuffer* ibo;
};