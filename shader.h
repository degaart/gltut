#pragma once

#include <string>
#include <GL/glew.h>

class Shader {
    public:
        Shader(std::string filename);
        Shader(const Shader&) = delete;
        virtual ~Shader();
        Shader& operator=(const Shader&) = delete;

        void Bind();
    private:
        static const int NUM_SHADERS = 2;
        GLuint m_program;
        GLuint m_shaders[NUM_SHADERS];

        static std::string LoadShader(std::string filename);
        static void CheckShaderError(GLuint shader,
                                     GLuint flag,
                                     bool isProgram,
                                     std::string errorMessage);
        GLuint CreateShader(std::string text,
                            GLenum type);
};

