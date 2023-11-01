#pragma once
#include <unordered_map>

#include "InputCodes.h"
#include "dll.h"


struct GLFWwindow;
class Window;

void keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods);


class KeyboardInput
{
public:

    L4_API KeyboardInput(Window& window);

    L4_API KeyboardInput(const KeyboardInput& obj) = delete;
    L4_API KeyboardInput& operator=(const KeyboardInput& obj) = delete;

    L4_API KeyboardInput(KeyboardInput&& obj) = delete;
    L4_API KeyboardInput& operator=(KeyboardInput&& obj) = delete;

    L4_API bool isKeyPressed(const KeyCode& key);

    L4_API void KeyboardCallback(const int32_t& key, const int32_t& action);
	
private:

	Window& m_window;

	std::unordered_map<uint32_t, bool> m_key_states;
};
