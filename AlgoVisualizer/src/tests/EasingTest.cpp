#include "EasingTest.h"

#include <glm/gtc/matrix_transform.hpp>

#include "anims/Timer.h"
#include "anims/Tweens.h"

EasingTest::EasingTest(Window* window)
	:
	Test(window)
{

	m_circle_renderer = new CircleRenderer();

	m_circle_1.position = glm::vec3(400.0f, 200.0f, 0.0f);
	m_circle_1.radius = 25.0f;
	m_circle_1.color = glm::vec4(0.0f, 1.0f, 0.0f, 1.0f);
	m_circle_1.border_width = 5.0f;
	m_circle_1.border_color = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);

	WindowSettings window_settings = window->getWindowSettings();

	glm::mat4 ortho_projection = glm::ortho(0.0f, (float)window_settings.width, 0.0f, (float)window_settings.height);

	m_mvp = ortho_projection;
}

EasingTest::~EasingTest()
{
	delete m_circle_renderer;
}

void EasingTest::onUpdate(const float& frame_time)
{
	static Tween linear_tween(TWEENS::EASE_IN_OUT, 2.0f);

	m_circle_1.position = glm::vec3(300.0f, 300.0f, 0.0f) * linear_tween.update(frame_time);
	
	m_circle_renderer->push(m_circle_1);
	m_circle_renderer->onUpdate(m_mvp);
}

void EasingTest::onImGuiUpdate()
{
}
