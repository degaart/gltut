#include "shader.h"

#include <fstream>
#include <iostream>

Shader::Shader(std::string filename)
{
    m_program = glCreateProgram();

    m_shaders[0] = CreateShader(LoadShader(filename + ".vs"), GL_VERTEX_SHADER);
    m_shaders[1] = CreateShader(LoadShader(filename + ".fs"), GL_FRAGMENT_SHADER);

    for(int i = 0; i < NUM_SHADERS; i++) {
        glAttachShader(m_program, m_shaders[i]);
    }

    glBindAttribLocation(m_program, 0, "position");

    glLinkProgram(m_program);
    CheckShaderError(m_program,
                     GL_LINK_STATUS,
                     true,
                     "Error: Program linking failed for \"" + filename + "\"");

    glValidateProgram(m_program);
    CheckShaderError(m_program,
                     GL_VALIDATE_STATUS,
                     true,
                     "Error: Program validation failed for \"" + filename + "\"");

}

Shader::~Shader()
{
    for(int i = 0; i < NUM_SHADERS; i++) {
        glDetachShader(m_program, m_shaders[i]);
        glDeleteShader(m_shaders[i]);
    }
    glDeleteProgram(m_program);
}

void Shader::Bind()
{
    glUseProgram(m_program);
}

std::string Shader::LoadShader(std::string filename)
{
    std::ifstream file;
    file.open(filename);

    std::string output;
    std::string line;

    if(file.is_open()) {
        while(file.good()) {
            getline(file, line);
            output.append(line + "\n");
        }
    } else {
        std::cerr << "Unable to load shader: " << filename << "\n";
    }
    
    return output;
}

void Shader::CheckShaderError(GLuint shader,
                              GLuint flag,
                              bool isProgram,
                              std::string errorMessage)
{
    GLint success = 0;
    GLchar error[1024] = { 0 };

    if(isProgram) {
        glGetProgramiv(shader, flag, &success);
    } else {
        glGetShaderiv(shader, flag, &success);
    }

    if(success == GL_FALSE) {
        if(isProgram) {
            glGetProgramInfoLog(shader, sizeof(error), NULL, error);
        } else {
            glGetShaderInfoLog(shader, sizeof(error), NULL, error);
        }
        std::cerr << errorMessage << ": \"" << error << "\"\n";
    }
}

GLuint Shader::CreateShader(std::string text,
                            GLenum type)
{
    GLuint shader = glCreateShader(type);

    if(shader == 0) {
        std::cerr << "Error: Shader creation failed\n";
    }

    const GLchar* shaderSourceStrings[1];
    GLint shaderSourceStringLengths[1];

    shaderSourceStrings[0] = text.c_str();
    shaderSourceStringLengths[0] = text.length();
    
    glShaderSource(shader, 1, shaderSourceStrings, shaderSourceStringLengths);
    glCompileShader(shader);

    CheckShaderError(shader,
                     GL_COMPILE_STATUS,
                     false,
                     "Error: Shader compilation failed");

    return shader;
}


