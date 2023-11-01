#pragma once
#include <cstdint>
#include <unordered_map>

#include "glm/glm.hpp"

#include "InputCodes.h"
#include "dll.h"

struct GLFWwindow;
class Window;


void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos);


class MouseInput
{
public:

    L4_API MouseInput(Window& window);

    L4_API MouseInput(const MouseInput& obj) = delete;
    L4_API MouseInput& operator=(const MouseInput& obj) = delete;

    L4_API MouseInput(MouseInput&& obj) = delete;
    L4_API MouseInput& operator=(MouseInput&& obj) = delete;

    L4_API bool isLeftButtonPressed();
    L4_API bool isRightButtonPressed();

    L4_API const glm::vec2& getLastCursorPosition() const;

    L4_API void MouseButtonCallback(const int32_t& button, const int32_t& action);
    L4_API void CursorPositionCallback(const double& xpos, const double& ypos);

private:

	Window& m_window;

	std::unordered_map<uint32_t, bool> m_button_states;

	glm::vec2 m_cursor_pos;
};

