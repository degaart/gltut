#include "mesh.h"
#include <iostream>

Mesh::Mesh(Vertex* vertices, int numVertices)
{
    m_drawCount = numVertices;


    std::cout << "glGenVertexArrays: " << glGenVertexArrays << "\n";

    GLuint arrays[10];
    glGenVertexArrays(1, arrays);
    m_vertexArrayObject = arrays[0];
    glBindVertexArray(m_vertexArrayObject);

    glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_VB]);
    glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(vertices[0]),
                 vertices,
                 GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindVertexArray(0);
}

Mesh::~Mesh()
{
    glDeleteVertexArrays(1, &m_vertexArrayObject);
}

void Mesh::Draw()
{
    glBindVertexArray(m_vertexArrayObject);

    glDrawArrays(GL_TRIANGLES, 0, m_drawCount);

    glBindVertexArray(0);
}

Vertex::Vertex(const glm::vec3& pos):
    m_pos(pos)
{
}

