#pragma once

#include <string>
#include <unordered_map>

#include <glm/glm.hpp>

struct ShaderProgramSource {
    std::string VertexSource;
    std::string FragmentSource;
};

class Shader {
public:
    Shader(const std::string& filepath);
    ~Shader();

    void bind() const;
    void unbind() const;

    // Set uniforms
    void setUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
    void setUniform1i(const std::string& name, unsigned int v0);
    void setUniformMat4f(const std::string& name, const glm::mat4& matrix);
private:
    unsigned int compileShader(const std::string& source, unsigned int type);
    unsigned int createShader(const std::string& vertexShader, const std::string& fragmentShader);
    ShaderProgramSource parseShader();
    bool compileShader();
    std::string m_filePath;
    unsigned int m_rendererID;
    // caching for uniforms
    int getUniformLocation(const std::string& name);

    std::unordered_map<std::string, int> m_uniformLocationCache;
};