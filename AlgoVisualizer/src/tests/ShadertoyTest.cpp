#include "ShadertoyTest.h"
#include <glm/gtc/matrix_transform.hpp>
#include <imgui/imgui.h>

#include "OpenGL/GL_Renderer.h"
#include "rectangle/RectangleGeometryGenerator.h"


ShadertoyTest::ShadertoyTest(Window* window)
	:
	Test(window)
{
	OpenGL::Renderer::setClearColor(glm::vec4(100.0f / 256.0f, 100.0f / 256.0f, 100.0f / 256.0f, 1.0f));

	m_shader = std::make_unique<OpenGL::Shader>("res/shaders/vBasic.glsl", "res/shaders/toy_9.glsl");
	m_va = std::make_unique<OpenGL::VertexArray>();
	m_vb = std::make_unique<OpenGL::VertexBuffer>(sizeof(RectangleBuffer) * 1, DrawType::STATIC);

	OpenGL::BufferLayout layout;
	layout.addAttribute<float>(3);

	m_va->addVertexBuffer(m_vb.get());
	m_va->setBufferLayout(layout);

	float buffer[] = {
		 320.0f,  540.0f, 0.0f,
		 320.0f,  180.0f, 0.0f,
		 960.0f,  180.0f, 0.0f,

		 320.0f,  540.0f, 0.0f,
		 960.0f,  180.0f, 0.0f,
		 960.0f,  540.0f, 0.0f
	};
	m_vb->create(buffer, sizeof(buffer), DrawType::STATIC);

	iResolution = glm::vec2(640.0f, 360.0f);

	WindowSettings window_settings = window->getWindowSettings();

	glm::mat4 ortho_projection = glm::ortho(0.0f, (float)window_settings.width, 0.0f, (float)window_settings.height);

	m_mvp = ortho_projection;
}

void ShadertoyTest::onUpdate(const float& dt)
{
	m_shader->bind();
	m_shader->setUniformMat4f("u_MVP", m_mvp);
	m_shader->setUniform1f("iTime", iTime);
	m_shader->setUniform2f("iResolution", iResolution);
	m_shader->setUniform2f("botLeft", glm::vec2(320.0f, 180.0f));

	iTime += dt;

	OpenGL::Renderer::drawArrays(*m_va, DrawUsage::TRIANGLE, 6);
}

void ShadertoyTest::onImGuiUpdate()
{
	//ImGui::SliderFloat3("Position", &props.position.x, 0.0f, 1280.0f);
	//ImGui::ColorEdit3("Color", &props.color.x, ImGuiColorEditFlags_::ImGuiColorEditFlags_Float);
	//ImGui::SliderFloat2("Size", &props.size.x, 0.0f, 400.0f);
	//ImGui::SliderFloat("Radius", &props.radius, 0.0f, 50.0f);
	//ImGui::SliderFloat("Border width", &props.border_width, 0.0f, 50.0f);
	//ImGui::ColorEdit3("Border color", &props.border_color.x, ImGuiColorEditFlags_::ImGuiColorEditFlags_Float);
}
