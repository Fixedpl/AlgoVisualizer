#pragma once
#include "Window.h"
#include "dll.h"


class Application
{
public:

    L4_API Application(const WindowSettings& window_settings);

    L4_API virtual void run() = 0;

protected:

    L4_API virtual void onUpdate(const float& dt) = 0;

    L4_API virtual void loop() = 0;

protected:
	
	Window m_window;

};

