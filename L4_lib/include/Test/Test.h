#pragma once
#include <functional>

#include <glm/glm.hpp>
#include "Core/Window.h"


class Test
{
public:

    L4_API Test();
    L4_API Test(Window* window);

    L4_API virtual void onUpdate(const float& frame_time) {};

    L4_API virtual void onImGuiUpdate() {};

private:

    void _onImGuiUpdate();

protected:

    Window* m_window;

private:

    std::function<void()> m_on_test_end_callback;

    friend class TestingEnvironment;
};

