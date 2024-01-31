#pragma once

#include<glad/glad.h>

#include <iostream>
#include <stdint.h>
#include <assert.h>

#define ASSERT(x) if (!(x)) __debugbreak();

#ifdef DEBUG
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__))
#else
#define GLCall(x) x
#endif


static void GLClearError()
{
    while (glGetError() != GL_NO_ERROR);
}

static bool GLLogCall(const char* function, const char* file, int line)
{
    while (GLenum error = glGetError())
    {

        std::cout << "[OpenGL Error]( " << error << "): " << function << " " <<
            file << ":" << line << std::endl;
        switch (error) {
        }
        return false;
    }
    return true;
}
