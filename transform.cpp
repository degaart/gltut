#include "transform.h"
#include <glm/gtx/transform.hpp>

Transform::Transform(glm::vec3 pos, glm::vec3 rot, glm::vec3 scale):
    m_pos(pos), m_rot(rot), m_scale(scale)
{
}


glm::vec3& Transform::GetPos()
{
    return m_pos;
}

glm::vec3& Transform::GetRot()
{
    return m_rot;
}

glm::vec3& Transform::GetScale()
{
    return m_scale;
}

void Transform::SetPos(glm::vec3 pos)
{
    m_pos = pos;
}

void Transform::SetRot(glm::vec3 rot)
{
    m_rot = rot;
}

void Transform::SetScale(glm::vec3 scale)
{
    m_scale = scale;
}

glm::mat4 Transform::GetModel() const
{
    glm::mat4 posMatrix = glm::translate(m_pos);
    glm::mat4 rotXMatrix = glm::rotate(m_rot.x, glm::vec3(1, 0, 0));
    glm::mat4 rotYMatrix = glm::rotate(m_rot.y, glm::vec3(0, 1, 0));
    glm::mat4 rotZMatrix = glm::rotate(m_rot.z, glm::vec3(0, 0, 1));
    glm::mat4 scaleMatrix = glm::scale(m_scale);

    glm::mat4 rotMatrix = rotZMatrix * rotYMatrix * rotXMatrix;

    return posMatrix * rotMatrix * scaleMatrix;
}

