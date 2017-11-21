#pragma once

#include <glm/glm.hpp>

class Transform {
    public:
        Transform(glm::vec3 pos = glm::vec3(),
                  glm::vec3 rot = glm::vec3(), 
                  glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f));

        glm::vec3& GetPos();
        glm::vec3& GetRot();
        glm::vec3& GetScale();

        void SetPos(glm::vec3 pos);
        void SetRot(glm::vec3 rot);
        void SetScale(glm::vec3 scale);

        glm::mat4 GetModel() const;
    private:
        glm::vec3 m_pos;
        glm::vec3 m_rot;
        glm::vec3 m_scale;
};

