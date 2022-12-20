#include <iostream>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>
#include <GL/glew.h>

#include "../util.h"
#include "object.h"

#include "../VertexArray.h"
#include "../VertexBuffer.h"
#include "../IndexBuffer.h"


using namespace glm;

void Object::setupVAO()
{
	va = new VertexArray();

	if (!vertices.empty()) {
		std::vector<float> vert;
		for(auto v : vertices) {
			vert.push_back(v.x);
			vert.push_back(v.y);
			vert.push_back(v.z);
		}
		vbo = new VertexBuffer(vert.data(), vert.size() * sizeof(float));
	}

	// if (!normals.empty()) {
	// 	GLuint bNormal;
	// 	glGenBuffers(1, &bNormal);
	// 	glBindBuffer(GL_ARRAY_BUFFER, bNormal);
	// 	glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(vec3), normals.data(), GL_STATIC_DRAW);
	// 	glEnableVertexAttribArray(ATTRIB_NORMAL);
	// 	glVertexAttribPointer(ATTRIB_NORMAL, 3, GL_FLOAT, GL_FALSE, 0, 0);
	// }

	// if (!texCoords.empty()) {
	// 	GLuint bTexCoord;
	// 	glGenBuffers(1, &bTexCoord);
	// 	glBindBuffer(GL_ARRAY_BUFFER, bTexCoord);
	// 	glBufferData(GL_ARRAY_BUFFER, texCoords.size() * sizeof(vec2), texCoords.data(), GL_STATIC_DRAW);
	// 	glEnableVertexAttribArray(ATTRIB_TEXCOORD);
	// 	glVertexAttribPointer(ATTRIB_TEXCOORD, 2, GL_FLOAT, GL_FALSE, 0, 0);
	// }

	VertexBufferLayout vbl;
	vbl.push<float>(3);
	va->addBuffer(*vbo, vbl);
	va->bind();

	if (!indices.empty()) {
		ibo = new IndexBuffer(indices.data(), indices.size());
	}
}

void Object::bind()
{
	GLCall(glBindVertexArray(vao));
}