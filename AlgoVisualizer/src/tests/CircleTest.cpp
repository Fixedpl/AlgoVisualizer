#include "CircleTest.h"
#include <glm/gtc/matrix_transform.hpp>
#include <imgui/imgui.h>

#include "OpenGL/GL_Renderer.h"
#include "circle/CircleBufferFiller.h"



CircleTest::CircleTest(Window* window)
	:
	Test(window)
{
	OpenGL::Renderer::setClearColor(glm::vec4(100.0f / 256.0f, 100.0f / 256.0f, 100.0f / 256.0f, 1.0f));

	m_shader = std::make_unique<OpenGL::Shader>("res/shaders/vCircle.glsl", "res/shaders/fCircle.glsl");
	m_va = std::make_unique<OpenGL::VertexArray>();
	m_vb = std::make_unique<OpenGL::VertexBuffer>(sizeof(CircleBuffer) * 1, DrawType::STATIC);

	OpenGL::BufferLayout circle_layout;
	circle_layout.addAttribute<float>(3);
	circle_layout.addAttribute<float>(2);
	circle_layout.addAttribute<float>(1);
	circle_layout.addAttribute<float>(4);
	circle_layout.addAttribute<float>(1);
	circle_layout.addAttribute<float>(4);

	uint32_t indices[] = {
		0, 1, 2, 0, 2, 3
	};
	m_ib = std::make_unique<OpenGL::IndexBuffer>(indices, 6);

	m_va->addVertexBuffer(m_vb.get());
	m_va->setBufferLayout(circle_layout);
	m_va->setIndexBuffer(m_ib.get());

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

void CircleTest::onUpdate(const float& dt)
{
	m_shader->bind();
	m_shader->setUniformMat4f("u_MVP", m_mvp);

	CircleBufferArray* circle_buffer = CircleBufferFiller::generate(circle);
	m_vb->update(circle_buffer->buffer->vertices, sizeof(CircleBuffer), 0);
	delete circle_buffer;

	OpenGL::Renderer::drawIndexed(*m_va, DrawUsage::TRIANGLE);
}

void CircleTest::onImGuiUpdate()
{
	ImGui::SliderFloat3("Position", &transform->pos.x, 0.0f, 1280.0f);
	ImGui::SliderFloat("Radius", &props->radius, 0.0f, 400.0f);
	ImGui::ColorEdit3("Color", &color->col.x, ImGuiColorEditFlags_::ImGuiColorEditFlags_Float);
	ImGui::SliderFloat("Border width", &border->width, 0.0f, 50.0f);
	ImGui::ColorEdit3("Border color", &border->color.x, ImGuiColorEditFlags_::ImGuiColorEditFlags_Float);
}
