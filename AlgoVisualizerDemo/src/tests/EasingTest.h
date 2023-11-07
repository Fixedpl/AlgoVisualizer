#pragma once
#include "Test/Test.h"

#include "circle/CircleRenderer.h"
#include "Entity/Entity.h"
#include "Entity/EntityRegistry.h"
#include "BaseComponents.h"


class EasingTest : public Test
{
public:

	EasingTest(Window* window);
	~EasingTest();

	void onUpdate(const float& frame_time);
	void onImGuiUpdate();

private:

	CircleRenderer* m_circle_renderer;

	EntityRegistry registry;
	Entity circle;

	Transform* transform;
	Color* color;
	CircleProps* props;
	Border* border;

	glm::mat4 m_mvp;

	float timer = 0.0f;
};

