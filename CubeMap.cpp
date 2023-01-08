#include "CubeMap.h"

CubeMap::CubeMap(std::vector<std::string> faces) {
    this->faces = faces;
    this->load();
}

void CubeMap::load(){
    GLCall(glGenTextures(1, &this->textureID));
    GLCall(glBindTexture(GL_TEXTURE_CUBE_MAP, this->textureID));

    int width, height, nrChannels;
    for (unsigned int i = 0; i < faces.size(); i++)
    {
        unsigned char *data = stbi_load(faces[i].c_str(), &width, &height, &nrChannels, 0);
        if (data)
        {
            GLCall(glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i,
                0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data
            );)
            stbi_image_free(data);
        }
        else
        {
            std::cout << "Cubemap texture failed to load at path: " << faces[i] << std::endl;
            stbi_image_free(data);
        }
    }
    GLCall(glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
    GLCall(glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
    GLCall(glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
    GLCall(glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));
    GLCall(glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE));

    this->shader = new Shader("resources/shaders/skybox.hlsl");
    this->initObject();
}

void CubeMap::initObject(){
    std::vector<float> skyboxVertices = {
        // positions          
        -1.0f,  1.0f, -1.0f,
        -1.0f, -1.0f, -1.0f,
        1.0f, -1.0f, -1.0f,
        1.0f, -1.0f, -1.0f,
        1.0f,  1.0f, -1.0f,
        -1.0f,  1.0f, -1.0f,

        -1.0f, -1.0f,  1.0f,
        -1.0f, -1.0f, -1.0f,
        -1.0f,  1.0f, -1.0f,
        -1.0f,  1.0f, -1.0f,
        -1.0f,  1.0f,  1.0f,
        -1.0f, -1.0f,  1.0f,

        1.0f, -1.0f, -1.0f,
        1.0f, -1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
        1.0f,  1.0f, -1.0f,
        1.0f, -1.0f, -1.0f,

        -1.0f, -1.0f,  1.0f,
        -1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
        1.0f, -1.0f,  1.0f,
        -1.0f, -1.0f,  1.0f,

        -1.0f,  1.0f, -1.0f,
        1.0f,  1.0f, -1.0f,
        1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
        -1.0f,  1.0f,  1.0f,
        -1.0f,  1.0f, -1.0f,

        -1.0f, -1.0f, -1.0f,
        -1.0f, -1.0f,  1.0f,
        1.0f, -1.0f, -1.0f,
        1.0f, -1.0f, -1.0f,
        -1.0f, -1.0f,  1.0f,
        1.0f, -1.0f,  1.0f
    };

    std::vector<unsigned int> skyboxIndices = {
        0, 1, 2, 3, 4, 5,
        6, 7, 8, 9, 10, 11,
        12, 13, 14, 15, 16, 17,
        18, 19, 20, 21, 22, 23,
        24, 25, 26, 27, 28, 29,
        30, 31, 32, 33, 34, 35
    };


    this->vao = new VertexArray();
    this->vbo = new VertexBuffer(skyboxVertices.data(), skyboxVertices.size() * sizeof(float));

    VertexBufferLayout layout;
    layout.push<float>(3);

    this->vao->addBuffer(*this->vbo, layout);

    this->ibo = new IndexBuffer(skyboxIndices.data(), 36);

}

void CubeMap::draw(Camera* camera) const {
    this->bind();
    this->shader->bind();
    this->shader->setUniformMat4f("u_View", camera->getViewMatrix());
    this->shader->setUniformMat4f("u_Projection", camera->getProjectionMatrix());

    glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(7.0f));
    this->shader->setUniformMat4f("u_Scale", scale);
    GLCall(glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0));
    this->shader->unbind();
    this->unbind();
}

void CubeMap::bind() const {
    GLCall(glBindTexture(GL_TEXTURE_CUBE_MAP, this->textureID));
    this->vao->bind();
    this->ibo->bind();
}

void CubeMap::unbind() const {
    this->vao->unbind();
    this->ibo->unbind();
    GLCall(glBindTexture(GL_TEXTURE_CUBE_MAP, 0));
}

