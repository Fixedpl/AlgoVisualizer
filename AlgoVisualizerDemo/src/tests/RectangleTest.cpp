#include "RectangleTest.h"
#include <glm/gtc/matrix_transform.hpp>
#include <imgui/imgui.h>

#include "OpenGL/GL_Renderer.h"
#include "rectangle/RectangleBufferFiller.h"
#include "BaseComponents.h"


RectangleTest::RectangleTest(Window* window)
	:
	Test(window)
{
	OpenGL::Renderer::setClearColor(glm::vec4(100.0f / 256.0f, 100.0f / 256.0f, 100.0f / 256.0f, 1.0f));

	m_shader = std::make_unique<OpenGL::Shader>("res/shaders/vRectangle.glsl", "res/shaders/fRectangle.glsl");
	m_va = std::make_unique<OpenGL::VertexArray>();
	m_vb = std::make_unique<OpenGL::VertexBuffer>(sizeof(RectangleBuffer) * 1, DrawType::STATIC);

	OpenGL::BufferLayout layout;
	layout.addAttribute<float>(3);
	layout.addAttribute<float>(2);
	layout.addAttribute<float>(4);
	layout.addAttribute<float>(2);
	layout.addAttribute<float>(1);
	layout.addAttribute<float>(1);
	layout.addAttribute<float>(4);
	layout.addAttribute<float>(1);

	uint32_t indices[] = {
		0, 1, 2, 0, 2, 3
	};
	m_ib = std::make_unique<OpenGL::IndexBuffer>(indices, 6);

	m_va->addVertexBuffer(m_vb.get());
	m_va->setBufferLayout(layout);
	m_va->setIndexBuffer(m_ib.get());

	rect = registry.createEntity();
	rect.add<Transform>(Transform());
	transform = &rect.get<Transform>();
	transform->pos = glm::vec3(0.0f, 0.0f, 0.0f);

	rect.add<Color>(Color());
	color = &rect.get<Color>();
	color->col = glm::vec4(1.0f, 1.0f, 0.0f, 1.0f);

	rect.add<RectProps>(RectProps());
	props = &rect.get<RectProps>();
	props->size = glm::vec2(100.0f, 80.0f);
	props->radius = 0.0f;
	props->sharpness = 0.0f;

	rect.add<Border>(Border());
	border = &rect.get<Border>();
	border->width = 0.0f;
	border->color = glm::vec4(glm::vec3(0.0f), 1.0f);

	WindowSettings window_settings = window->getWindowSettings();

	glm::mat4 ortho_projection = glm::ortho(0.0f, (float)window_settings.width, 0.0f, (float)window_settings.height);

	m_mvp = ortho_projection;
}

void RectangleTest::onUpdate(const float& dt)
{
	m_shader->bind();
	m_shader->setUniformMat4f("u_MVP", m_mvp);


	RectangleBufferArray* buffer = RectangleBufferFiller::generate(rect);
	m_vb->update(buffer->buffer->vertices, sizeof(RectangleBuffer), 0);
	delete buffer;

	OpenGL::Renderer::drawIndexed(*m_va, DrawUsage::TRIANGLE);
}

void RectangleTest::onImGuiUpdate()
{
	ImGui::SliderFloat3("Position", &transform->pos.x, 0.0f, 1280.0f);
	ImGui::ColorEdit4("Color", &color->col.x, ImGuiColorEditFlags_::ImGuiColorEditFlags_Float);
	ImGui::SliderFloat2("Size", &props->size.x, 0.0f, 400.0f);
	ImGui::SliderFloat("Border radius", &props->radius, 0.0f, 40.0f);
	ImGui::SliderFloat("Border width", &border->width, 0.0f, 20.0f);
	ImGui::ColorEdit3("Border color", &border->color.x, ImGuiColorEditFlags_::ImGuiColorEditFlags_Float);
	ImGui::SliderFloat("Border sharpness", &props->sharpness, 0.0f, 10.0f);
}

