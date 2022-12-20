#pragma once

#include <stdlib.h>

void GLClearError();
bool GLLogCall(const char* function, const char* file, int line);
void GLCheckError();

#define ASSERT(x) if(!(x)) exit(0);

#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__));






