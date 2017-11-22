#pragma once

#include <glm/glm.hpp>
#include <GL/glew.h>
#include "obj_loader.h"

class Vertex {
    public:
        Vertex(glm::vec3 pos,
               glm::vec2 texCoord,
               glm::vec3 normal = glm::vec3(0, 0, 0));

        glm::vec3* GetPos();
        glm::vec2* GetTexCoord();
        glm::vec3* GetNormal();

    private:
        glm::vec3 m_pos;
        glm::vec2 m_texCoord;
        glm::vec3 m_normal;
};

class Mesh {
    public:
        Mesh(Vertex* vertices, int numVertices,
             int* indices, int numIndices);
        Mesh(std::string filename);
        Mesh(const Mesh&) = delete;
        Mesh& operator=(const Mesh&) = delete;
        virtual ~Mesh();

        void Draw();

    private:

        enum {
            POSITION_VB,
            TEXCOORD_VB,
            NORMAL_VB,
            INDEX_VB,
            NUM_BUFFERS
        };

        GLuint m_vertexArrayObject;
        GLuint m_vertexArrayBuffers[NUM_BUFFERS];
        unsigned int m_drawCount;

        void InitMesh(const IndexedModel& model);

};

