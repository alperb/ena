#include <GL/glew.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "util.h"
#include "Shader.h"


Shader::Shader(const std::string& filepath) : m_filePath(filepath), m_rendererID(0) {
    ShaderProgramSource src = parseShader();
    this->m_rendererID = createShader(src.VertexSource, src.FragmentSource);
}

Shader::~Shader() {
    GLCall(glDeleteProgram(this->m_rendererID));
}

void Shader::bind() const {
    GLCall(glUseProgram(this->m_rendererID));
}

void Shader::unbind() const {
    GLCall(glUseProgram(0));
}

void Shader::setUniform4f(const std::string& name, float v0, float v1, float v2, float v3) {
    GLCall(glUniform4f(getUniformLocation(name), v0, v1, v2, v3));
}

int Shader::getUniformLocation(const std::string& name) {
    GLCall(int location = glGetUniformLocation(this->m_rendererID, name.c_str()));
    if(location == -1) {
        std::cout << "Warning: uniform '" << name << "' doesn't exist!" << std::endl;
    }
    return location;
}

ShaderProgramSource Shader::parseShader() {
    std::ifstream stream(this->m_filePath);
    enum class ShaderType {
        NONE = -1, VERTEX = 0, FRAGMENT = 1
    };
    ShaderType type = ShaderType::NONE;
    std::stringstream ss[2];

    std::string line;
    while(getline(stream, line)) {
        if(line.find("#shader") != std::string::npos) {
            if(line.find("vertex") != std::string::npos) {
                type = ShaderType::VERTEX;
            } else if(line.find("fragment") != std::string::npos) {
                type = ShaderType::FRAGMENT;
            }
        } else {
            ss[(int)type] << line << std::endl;
        }
    }

    return {ss[0].str(), ss[1].str()};
}

unsigned int Shader::compileShader(const std::string& source, unsigned int type) {
    GLCall(unsigned int id = glCreateShader(type));
    const char* src = source.c_str();
    GLCall(glShaderSource(id, 1, &src, nullptr));
    GLCall(glCompileShader(id));

    int result;
    GLCall(glGetShaderiv(id, GL_COMPILE_STATUS, &result));
    if(result == GL_FALSE) {
        int length;
        GLCall(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length));
        char* message = (char*)alloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);
        std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader!" << std::endl;
        std::cout << message << std::endl;
        GLCall(glDeleteShader(id));
        return 0;
    }

    return id;
}

unsigned int Shader::createShader(const std::string& vertexShader, const std::string& fragmentShader){
    unsigned int program = glCreateProgram();
    unsigned int vs = compileShader(vertexShader, GL_VERTEX_SHADER);
    unsigned int fs = compileShader(fragmentShader, GL_FRAGMENT_SHADER);

    GLCall(glAttachShader(program, vs));
    GLCall(glAttachShader(program, fs));
    GLCall(glLinkProgram(program));
    GLCall(glValidateProgram(program));

    GLCall(glDeleteShader(vs));
    GLCall(glDeleteShader(fs));

    return program;
}