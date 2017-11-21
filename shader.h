#pragma once

#include <string>
#include <GL/glew.h>
#include "transform.h"
#include "camera.h"

class Shader {
    public:
        Shader(std::string filename);
        Shader(const Shader&) = delete;
        virtual ~Shader();
        Shader& operator=(const Shader&) = delete;

        void Bind();
        void Update(const Transform& transform, const Camera& camera);
    private:
        static const int NUM_SHADERS = 2;
        enum {
            TRANSFORM_U,
            NUM_UNIFORMS
        };

        GLuint m_program;
        GLuint m_shaders[NUM_SHADERS];
        GLuint m_uniforms[NUM_UNIFORMS];

        static std::string LoadShader(std::string filename);
        static void CheckShaderError(GLuint shader,
                                     GLuint flag,
                                     bool isProgram,
                                     std::string errorMessage);
        GLuint CreateShader(std::string text,
                            GLenum type);
};

