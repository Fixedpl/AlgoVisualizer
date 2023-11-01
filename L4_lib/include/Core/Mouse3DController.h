#pragma once
#include <glm/glm.hpp>

#include "dll.h"





class Mouse3DController
{
public:

    L4_API Mouse3DController();

    L4_API glm::vec3 registerMouseMovement(const glm::vec2& pos);

    L4_API float getSensitivity() const;
    L4_API void setSensitivity(const float& sens);

    L4_API void registerNextMoveAsFirst();

private:

    bool m_first_mouse_move;

    glm::vec2 m_last_mouse_pos;

    float m_yaw;
    float m_pitch;

    float m_sensitivity;

};

