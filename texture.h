#pragma once

#include <string>
#include <GL/glew.h>

class Texture {
    public:
        Texture(std::string filename);
        Texture(const Texture&) = delete;
        Texture& operator=(const Texture&) = delete;
        virtual ~Texture();

        void Bind(int unit);

    private:
        GLuint m_texture;

};

