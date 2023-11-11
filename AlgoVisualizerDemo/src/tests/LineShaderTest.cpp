#include "LineShaderTest.h"
#include <glm/gtc/matrix_transform.hpp>
#include <imgui/imgui.h>

#include "OpenGL/GL_Renderer.h"
#include "line/LineBufferFiller.h"
#include "BaseComponents.h"


LineShaderTest::LineShaderTest(Window* window)
	:
	Test(window)
{
	OpenGL::Renderer::setClearColor(glm::vec4(100.0f / 256.0f, 100.0f / 256.0f, 100.0f / 256.0f, 1.0f));

	m_shader = std::make_unique<OpenGL::Shader>("res/shaders/vLine.glsl", "res/shaders/fLine.glsl");
	m_va = std::make_unique<OpenGL::VertexArray>();
	m_vb = std::make_unique<OpenGL::VertexBuffer>(sizeof(LineBuffer) * 1, DrawType::STATIC);

	OpenGL::BufferLayout layout;
	layout.addAttribute<float>(3);
	layout.addAttribute<float>(4);
	layout.addAttribute<float>(2);
	layout.addAttribute<float>(2);
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
	props->radius = 0.0f;
	props->sharpness = 2.0f;


	WindowSettings window_settings = window->getWindowSettings();

	glm::mat4 ortho_projection = glm::ortho(0.0f, (float)window_settings.width, 0.0f, (float)window_settings.height);

	m_mvp = ortho_projection;
}

void LineShaderTest::onUpdate(const float& dt)
{
	m_shader->bind();
	m_shader->setUniformMat4f("u_MVP", m_mvp);


	LineBufferArray* buffer = LineBufferFiller::generate(line);
	m_vb->update(buffer->buffer->vertices, sizeof(LineBuffer), 0);
	delete buffer;

	OpenGL::Renderer::drawIndexed(*m_va, DrawUsage::TRIANGLE);
}

void LineShaderTest::onImGuiUpdate()
{
	ImGui::SliderFloat3("Position", &transform->pos.x, 0.0f, 1280.0f);
	ImGui::ColorEdit4("Color", &color->col.x, ImGuiColorEditFlags_::ImGuiColorEditFlags_Float);
	ImGui::SliderFloat2("Vec", &props->vec.x, -100.0f, 100.0f);
	ImGui::SliderFloat("Thickness", &props->thickness, 0.0f, 20.0f);
	ImGui::SliderFloat("Sharpness", &props->sharpness, 0.0f, 10.0f);
	ImGui::ColorEdit4("Border color", &border->color.x, ImGuiColorEditFlags_::ImGuiColorEditFlags_Float);
	ImGui::SliderFloat("Border width", &border->width, 0.0f, 20.0f);
}
