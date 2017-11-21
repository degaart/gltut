#include "camera.h"

#include <glm/gtx/transform.hpp>

Camera::Camera(glm::vec3 pos, float fov, float aspect, float zNear, float zFar):
    m_perspective(glm::perspective(fov, aspect, zNear, zFar)),
    m_position(pos),
    m_forward(glm::vec3(0.0f, 0.0f, 1.0f)),
    m_up(glm::vec3(0.0f, 1.0f, 0.0f))
{
}

glm::mat4 Camera::GetViewProjection() const
{
    glm::mat4 result = m_perspective * glm::lookAt(m_position, 
                                                   m_position + m_forward,
                                                   m_up);
    return result;
}



