#pragma once
#include "Tests/Test.h"

#include "circle/CircleRenderer.h"


class EasingTest : public Test
{
public:

	EasingTest(Window* window);
	~EasingTest();

	void onUpdate(const float& frame_time);
	void onImGuiUpdate();

private:

	CircleRenderer* m_circle_renderer;

	CircleProperties m_circle_1;

	glm::mat4 m_mvp;

	float timer = 0.0f;
};

