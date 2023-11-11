#include "LineTest.h"
#include <glm/gtc/matrix_transform.hpp>
#include <imgui/imgui.h>

#include "OpenGL/GL_Renderer.h"
#include "line/LineBufferFiller.h"
#include "BaseComponents.h"


LineTest::LineTest(Window* window)
	:
	Test(window)
{
	OpenGL::Renderer::setClearColor(glm::vec4(100.0f / 256.0f, 100.0f / 256.0f, 100.0f / 256.0f, 1.0f));

	m_line_ren = std::make_unique<LineRenderer>();

	line = registry.createEntity();
	line.add<Transform>(Transform());
	transform = &line.get<Transform>();
	transform->pos = glm::vec3(0.0f, 0.0f, 0.0f);

	line.add<Color>(Color());
	color = &line.get<Color>();
	color->col = glm::vec4(1.0f, 1.0f, 0.0f, 1.0f);

	line.add<Border>(Border());
	border = &line.get<Border>();
	border->color = glm::vec4(1.0f, 1.0f, 0.0f, 1.0f);
	border->width = 0.0f;

	line.add<LineProps>(LineProps());
	props = &line.get<LineProps>();
	props->vec = glm::vec2(100.0f, 60.0f);
	props->thickness = 10.0f;
	props->sharpness = 2.0f;

	buffer = LineBufferFiller::generate(line);

	WindowSettings window_settings = window->getWindowSettings();

	glm::mat4 ortho_projection = glm::ortho(0.0f, (float)window_settings.width, 0.0f, (float)window_settings.height);

	m_mvp = ortho_projection;
}

void LineTest::onUpdate(const float& dt)
{
	LineBufferFiller::update(line, buffer->buffer);
	m_line_ren->push(buffer);

	m_line_ren->onUpdate(m_mvp);
}

void LineTest::onImGuiUpdate()
{
	ImGui::SliderFloat3("Position", &transform->pos.x, 0.0f, 1280.0f);
	ImGui::ColorEdit4("Color", &color->col.x, ImGuiColorEditFlags_::ImGuiColorEditFlags_Float);
	ImGui::SliderFloat2("Vec", &props->vec.x, -100.0f, 100.0f);
	ImGui::SliderFloat("Thickness", &props->thickness, 0.0f, 20.0f);
	ImGui::SliderFloat("Sharpness", &props->sharpness, 0.0f, 10.0f);
	ImGui::ColorEdit4("Border color", &border->color.x, ImGuiColorEditFlags_::ImGuiColorEditFlags_Float);
	ImGui::SliderFloat("Border width", &border->width, 0.0f, 20.0f);
}