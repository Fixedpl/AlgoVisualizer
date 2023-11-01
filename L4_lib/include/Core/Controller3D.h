#pragma once

#include "Core/Mouse3DController.h"
#include "Core/KeyboardInput.h"
#include "Core/MouseInput.h"
#include "Core/Window.h"


class Controller3D
{
public:

    L4_API Controller3D(Window& window);

    L4_API void handleCamera(const float& dt);

    L4_API const glm::mat4& mvp() const;

    L4_API float getMovementSpeed() const;
    L4_API void setMovementSpeed(const float& speed);

    L4_API glm::vec3 getPosition() const;
    L4_API void setPosition(const glm::vec3& position);

private:

    glm::vec3 handleCameraMouse();
    void handleCameraKeyboard(const float& dt, const glm::vec3& direction);

    void handleFlyingMode();
    void setFlyingMode(bool value);

    void calculateMvp(const glm::vec3& direction_vector);

private:

    Window& m_window;

    KeyboardInput* m_keyboard;
    MouseInput* m_mouse;

    Mouse3DController m_3d_mouse_controller;

    glm::mat4 m_mvp;
    glm::mat4 m_perspective;
    glm::mat4 m_view;

    glm::vec3 m_pos;

    float m_movement_speed;

    bool m_flying_mode;
};
