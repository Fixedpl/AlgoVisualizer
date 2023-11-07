#include "NodeTest.h"

#include <glm/gtc/matrix_transform.hpp>
#include <imgui/imgui.h>

#include "node/NodeFactory.h"
#include "Colors.h"


NodeTest::NodeTest(Window* window)
	:
	Test(window)
{
	m_text_ren = std::make_unique<TextRenderer>();
	m_circle_ren = std::make_unique<CircleRenderer>();

	node = NodeFactory::node("14", 50.0f, COLOR::YELLOW, glm::vec3(0.0f), m_text_ren->getFont(), &registry);
	transform = &node.get<Transform>();
	props = &node.get<NodeProps>();
	color = &props->circle.get<Color>();
	circle_props = &props->circle.get<CircleProps>();

	buffer = NodeGG::generate(node);

	WindowSettings window_settings = window->getWindowSettings();
	glm::mat4 ortho_projection = glm::ortho(0.0f, (float)window_settings.width, 0.0f, (float)window_settings.height);
	m_mvp = ortho_projection;
}

void NodeTest::onUpdate(const float& frame_time)
{
	NodeFactory::update(node);
	NodeGG::update(node, buffer.circle_buffer, buffer.text_buffer);

	m_text_ren->push(buffer.text_buffer);
	m_circle_ren->push(buffer.circle_buffer);

	m_circle_ren->onUpdate(m_mvp);
	m_text_ren->onUpdate(m_mvp);
}

void NodeTest::onImGuiUpdate()
{
	ImGui::SliderFloat3("Position", &transform->pos.x, 0.0f, 1280.0f);
	ImGui::SliderFloat("Radius", &circle_props->radius, 0.0f, 400.0f);
	ImGui::ColorEdit3("Color", &color->col.x, ImGuiColorEditFlags_::ImGuiColorEditFlags_Float);
}
