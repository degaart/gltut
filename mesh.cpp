#include "mesh.h"
#include <iostream>
#include <vector>
#include "obj_loader.h"

Mesh::Mesh(std::string filename)
{
    IndexedModel model = OBJModel(filename).ToIndexedModel();
    InitMesh(model);
}

Mesh::Mesh(Vertex* vertices, int numVertices, int* indices, int numIndices)
{
    IndexedModel model;

    for(int i = 0; i < numVertices; i++) {
        model.positions.push_back(*vertices[i].GetPos());
        model.texCoords.push_back(*vertices[i].GetTexCoord());
        model.normals.push_back(*vertices[i].GetNormal());

    }

    for(int i = 0; i < numIndices; i++) {
        model.indices.push_back(indices[i]);
    }

    InitMesh(model);
}

Mesh::~Mesh()
{
    glDeleteVertexArrays(1, &m_vertexArrayObject);
}

void Mesh::InitMesh(const IndexedModel& model)
{
    m_drawCount = model.indices.size();

    glGenVertexArrays(1, &m_vertexArrayObject);
    glBindVertexArray(m_vertexArrayObject);

    glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);

    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_VB]);
    glBufferData(GL_ARRAY_BUFFER, model.positions.size() * sizeof(model.positions[0]),
                 &model.positions[0],
                 GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[TEXCOORD_VB]);
    glBufferData(GL_ARRAY_BUFFER, model.positions.size() * sizeof(model.texCoords[0]),
                 &model.texCoords[0],
                 GL_STATIC_DRAW);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[NORMAL_VB]);
    glBufferData(GL_ARRAY_BUFFER, model.normals.size() * sizeof(model.normals[0]),
                 &model.normals[0],
                 GL_STATIC_DRAW);

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vertexArrayBuffers[INDEX_VB]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, model.indices.size() * sizeof(model.indices[0]),
                 &model.indices[0],
                 GL_STATIC_DRAW);

    glBindVertexArray(0);
}

void Mesh::Draw()
{
    glBindVertexArray(m_vertexArrayObject);

    glDrawElements(GL_TRIANGLES, m_drawCount, GL_UNSIGNED_INT, 0);

    glBindVertexArray(0);
}

Vertex::Vertex(glm::vec3 pos, glm::vec2 texCoord, glm::vec3 normal):
    m_pos(pos), m_texCoord(texCoord), m_normal(normal)
{
}

glm::vec3* Vertex::GetPos()
{
    return &m_pos;
}

glm::vec2* Vertex::GetTexCoord()
{
    return &m_texCoord;
}

glm::vec3* Vertex::GetNormal()
{
    return &m_normal;
}


