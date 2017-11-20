#pragma once

#include <glm/glm.hpp>
#include <GL/glew.h>

class Vertex {
    public:
        Vertex(const glm::vec3& pos, const glm::vec2& texCoord);

        glm::vec3* GetPos();
        glm::vec2* GetTexCoord();

    private:
        glm::vec3 m_pos;
        glm::vec2 m_texCoord;
};

class Mesh {
    public:
        Mesh(Vertex* vertices, int numVertices);
        Mesh(const Mesh&) = delete;
        Mesh& operator=(const Mesh&) = delete;
        virtual ~Mesh();

        void Draw();

    private:

        enum {
            POSITION_VB,
            TEXCOORD_VB,
            NUM_BUFFERS
        };

        GLuint m_vertexArrayObject;
        GLuint m_vertexArrayBuffers[NUM_BUFFERS];
        unsigned int m_drawCount;

};
