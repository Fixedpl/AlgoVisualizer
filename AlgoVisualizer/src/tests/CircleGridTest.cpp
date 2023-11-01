#include "CircleGridTest.h"
#include <glm/gtc/matrix_transform.hpp>
#include <imgui/imgui.h>

#include "OpenGL/GL_Renderer.h"
#include "utils.h"
#include "circle/CircleGeometryGenerator.h"


CircleGridTest::CircleGridTest(Window* window)
	:
	Test(window),
	m_circle_count_vertical(10)
{
	OpenGL::Renderer::setClearColor(glm::vec4(100.0f / 256.0f, 100.0f / 256.0f, 100.0f / 256.0f, 1.0f));

	m_shader = std::make_unique<OpenGL::Shader>("res/shaders/vCircle.glsl", "res/shaders/fCircle.glsl");
	m_va = std::make_unique<OpenGL::VertexArray>();
	m_vb = std::make_unique<OpenGL::VertexBuffer>(sizeof(CircleBuffer) * 1, DrawType::DYNAMIC);

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

	m_circle_props.position = glm::vec3(0.0f, 0.0f, 0.0f);
	m_circle_props.radius = 50.0f;
	m_circle_props.color = glm::vec4(1.0f, 1.0f, 0.0f, 1.0f);
	m_circle_props.border_width = 1.0f;
	m_circle_props.border_color = glm::vec4(glm::vec3(0.0f), 1.0f);

	WindowSettings window_settings = window->getWindowSettings();

	glm::mat4 ortho_projection = glm::ortho(0.0f, (float)window_settings.width, 0.0f, (float)window_settings.height);

	m_mvp = ortho_projection;
}

void CircleGridTest::onUpdate(const float& dt)
{
	m_shader->bind();
	m_shader->setUniformMat4f("u_MVP", m_mvp);

	generateGrid();
	CircleBufferArray* buffer_arr = CircleGeometryGenerator::generate(m_circles);
	m_vb->create(buffer_arr->buffer, buffer_arr->size, DrawType::DYNAMIC);
	
	uint32_t* indices = Utils::generateIndicesForRects(buffer_arr->count);
	m_ib->create(indices, buffer_arr->count * 6);

	delete buffer_arr;
	m_circles.clear();
	delete[] indices;

	OpenGL::Renderer::drawIndexed(*m_va, DrawUsage::TRIANGLE);
}

void CircleGridTest::onImGuiUpdate()
{
	float imgui_framerate = ImGui::GetIO().Framerate;
	float ms_per_frame = 1000.0f / imgui_framerate;
	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", ms_per_frame, imgui_framerate);

	ImGui::SliderFloat3("Position", &m_circle_props.position.x, 0.0f, 1280.0f);
	ImGui::SliderFloat("Radius", &m_circle_props.radius, 0.0f, 400.0f);
	ImGui::ColorEdit3("Color", &m_circle_props.color.x, ImGuiColorEditFlags_::ImGuiColorEditFlags_Float);
	ImGui::SliderFloat("Border width", &m_circle_props.border_width, 0.0f, 50.0f);
	ImGui::ColorEdit3("Border color", &m_circle_props.border_color.x, ImGuiColorEditFlags_::ImGuiColorEditFlags_Float);
	ImGui::SliderInt("Grid size", &m_circle_count_vertical, 2, 20);
}

void CircleGridTest::generateGrid()
{
	WindowSettings window_settings = m_window->getWindowSettings();

	m_circle_props.radius = (float)window_settings.height / (m_circle_count_vertical * 2);
	float twice_radius = m_circle_props.radius * 2;

	m_circle_count_horizontal = std::ceil(window_settings.width / twice_radius);

	CircleProperties circle = m_circle_props;
	for (int i = 0; i < m_circle_count_vertical; i++) {
		for (int j = 0; j < m_circle_count_horizontal; j++) {
			m_circles.push_back(circle);
			circle.position += glm::vec3(twice_radius, 0.0f, 0.0f);
		}
		circle.position += glm::vec3(0.0f, twice_radius, 0.0f);
		circle.position.x = 0.0f;
	}
}
