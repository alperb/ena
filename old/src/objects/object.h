#pragma once

#include <vector>

#include "../VertexArray.h"
#include "../VertexBuffer.h"
#include "../IndexBuffer.h"
#include "../Renderer.h"


class Object
{
public:
	Object() {}
	virtual ~Object() {}
	virtual void bind();
	virtual void render() {}

protected:
	Renderer renderer;
	virtual void setupVAO();

	VertexArray* va;
	VertexBuffer* vbo;
	IndexBuffer* ibo;
	
	GLuint vao;
	std::vector<glm::vec3> vertices, normals;
	std::vector<glm::vec2> texCoords;
	std::vector<GLuint> indices;
};