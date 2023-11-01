#include "RectangleTest.h"
#include <glm/gtc/matrix_transform.hpp>
#include <imgui/imgui.h>

#include "OpenGL/GL_Renderer.h"
#include "rectangle/RectangleGeometryGenerator.h"


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

	props.position = glm::vec3(0.0f, 0.0f, 0.0f);
	props.color = glm::vec4(1.0f, 1.0f, 0.0f, 1.0f);
	props.size = glm::vec2(100.0f, 80.0f);
	props.radius = 0.0f;
	props.border_width = 0.0f;
	props.border_color = glm::vec4(glm::vec3(0.0f), 1.0f);
	props.sharpness = 0.0f;

	WindowSettings window_settings = window->getWindowSettings();

	glm::mat4 ortho_projection = glm::ortho(0.0f, (float)window_settings.width, 0.0f, (float)window_settings.height);

	m_mvp = ortho_projection;
}

void RectangleTest::onUpdate(const float& dt)
{
	m_shader->bind();
	m_shader->setUniformMat4f("u_MVP", m_mvp);

	RectangleBuffer* buffer = RectangleGeometryGenerator::generate(props);
	m_vb->update(buffer->vertices, sizeof(RectangleBuffer), 0);
	delete buffer;

	OpenGL::Renderer::drawIndexed(*m_va, DrawUsage::TRIANGLE);
}

void RectangleTest::onImGuiUpdate()
{
	ImGui::SliderFloat3("Position", &props.position.x, 0.0f, 1280.0f);
	ImGui::ColorEdit4("Color", &props.color.x, ImGuiColorEditFlags_::ImGuiColorEditFlags_Float);
	ImGui::SliderFloat2("Size", &props.size.x, 0.0f, 400.0f);
	ImGui::SliderFloat("Border radius", &props.radius, 0.0f, 40.0f);
	ImGui::SliderFloat("Border width", &props.border_width, 0.0f, 20.0f);
	ImGui::ColorEdit3("Border color", &props.border_color.x, ImGuiColorEditFlags_::ImGuiColorEditFlags_Float);
	ImGui::SliderFloat("Border sharpness", &props.sharpness, 0.0f, 10.0f);
}

