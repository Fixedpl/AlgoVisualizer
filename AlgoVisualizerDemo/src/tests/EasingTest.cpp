#include "EasingTest.h"

#include <glm/gtc/matrix_transform.hpp>

#include "anims/Timer.h"
#include "anims/Tweens.h"
#include "circle/CircleBufferFiller.h"


EasingTest::EasingTest(Window* window)
	:
	Test(window)
{

	m_circle_renderer = new CircleRenderer();


	circle = registry.createEntity();
	circle.add<Transform>(Transform());
	transform = &circle.get<Transform>();
	transform->pos = glm::vec3(0.0f, 0.0f, 0.0f);

	circle.add<Color>(Color());
	color = &circle.get<Color>();
	color->col = glm::vec4(1.0f, 1.0f, 0.0f, 1.0f);

	circle.add<CircleProps>(CircleProps());
	props = &circle.get<CircleProps>();
	props->radius = 50.0f;

	circle.add<Border>(Border());
	border = &circle.get<Border>();
	border->width = 1.0f;
	border->color = glm::vec4(glm::vec3(0.0f), 1.0f);

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
	static Tween linear_tween(TWEENS::EASE_IN_OUT_SIN, 2.0f);

	circle.get<Transform>().pos = glm::vec3(300.0f, 300.0f, 0.0f) * linear_tween.update(frame_time);
	CircleBufferArray* buffer = CircleBufferFiller::generate(circle);

	m_circle_renderer->push(buffer);

	m_circle_renderer->onUpdate(m_mvp);

	delete buffer;
}

void EasingTest::onImGuiUpdate()
{
}
