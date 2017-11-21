#pragma once

#include <glm/glm.hpp>

class Camera {
    public:
        Camera(glm::vec3 pos, float fov, float aspect, float zNear, float zFar);

        glm::mat4 GetViewProjection() const;

    private:
        glm::mat4 m_perspective;
        glm::vec3 m_position;
        glm::vec3 m_forward;
        glm::vec3 m_up;
};

