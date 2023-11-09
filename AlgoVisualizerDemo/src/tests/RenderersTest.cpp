#include "RenderersTest.h"
#include <glm/gtc/matrix_transform.hpp>
#include <imgui/imgui.h>

#include "OpenGL/GL_Renderer.h"

RenderersTest::RenderersTest(Window* window)
	:
	Test(window)
{
	OpenGL::Renderer::setClearColor(glm::vec4(100.0f / 256.0f, 100.0f / 256.0f, 100.0f / 256.0f, 1.0f));

	m_circles_ren = std::make_unique<CircleRenderer>();
	m_rect_ren = std::make_unique<RectangleRenderer>();
	m_text_ren = std::make_unique<TextRenderer>();

	WindowSettings window_set = window->getWindowSettings();

	m_mvp = glm::ortho(0.0f, (float)window_set.width, 0.0f, (float)window_set.height);

	node1.pos = glm::vec3(800.0f, 400.0f, 0.0f);
	node1.text = "1";

	node2.pos = glm::vec3(800.0f, 600.0f, 0.0f);
	node2.text = "2";
}

void RenderersTest::onUpdate(const float& frame_time)
{
	// CircleProperties circle;
	// circle.position = glm::vec3(100.0f, 100.0f, 0.0f);
	// circle.radius = 50.0f;
	// circle.color = glm::vec4(1.0f, 1.0f, 0.0f, 1.0f);
	// circle.border_width = 1.0f;
	// circle.border_color = glm::vec4(glm::vec3(0.0f), 1.0f);
	// 
	// //m_circles_ren->push(circle);
	// 
	// circle.position += glm::vec3(100.0f, 0.0f, 0.0f);
	// 
	// //m_circles_ren->push(circle);
	// 
	// RectangleProperties rectangle;
	// rectangle.position = glm::vec3(300.0f, 100.0f, 0.0f);
	// rectangle.size = glm::vec2(100.0f, 50.0f);
	// rectangle.color = glm::vec4(1.0f, 1.0f, 0.0f, 1.0f);
	// rectangle.radius = 4.0f;
	// rectangle.border_color = glm::vec4(glm::vec3(0.0f), 1.0f);
	// rectangle.border_width = 2.0f;
	// 
	// //m_rect_ren->push(rectangle);
	// 
	// rectangle.position += glm::vec3(100.0f, 0.0f, 0.0f);
	// 
	// //m_rect_ren->push(rectangle);
	// 
	// Text text;
	// text.text = "Andrzej";
	// text.props.position = glm::vec3(400.0f, 400.0f, 0.0f);
	// text.props.color = glm::vec4(glm::vec3(0.0f), 1.0f);
	// text.props.font_size = 40.0f;
	// 
	// //m_text_ren->push(text);
	// 
	// Text text2;
	// text2.text = "Rafal";
	// text2.props.position = glm::vec3(600.0f, 400.0f, 0.0f);
	// text2.props.color = glm::vec4(1.0f, 1.0f, 0.0f, 1.0f);
	// text2.props.font_size = 30.0f;
	// 
	// //m_text_ren->push(text2);
	// 
	// push(node1);
	// push(node2);
	// 
	// m_circles_ren->onUpdate(m_mvp);
	// m_rect_ren->onUpdate(m_mvp);
	// m_text_ren->onUpdate(m_mvp);
}

void RenderersTest::onImGuiUpdate()
{
	ImGui::SliderFloat3("node1 pos", &node1.pos.x, 0.0f, 1280.0f);
	ImGui::SliderFloat3("node2 pos", &node2.pos.x, 0.0f, 1280.0f);
}

void RenderersTest::push(const Node& node)
{
	//CircleProperties circle;
	//circle.position = node.pos;
	//circle.radius = 20.0f;
	//circle.color = glm::vec4(1.0f, 1.0f, 0.0f, 1.0f);
	//circle.border_width = 2.0f;
	//circle.border_color = glm::vec4(glm::vec3(0.0f), 1.0f);
	//
	////m_circles_ren->push(circle);
	//
	//Text text;
	//text.text = node.text;
	//text.props.position = node.pos + glm::vec3(13.0f, 10.0f, 0.0f);
	//text.props.color = glm::vec4(glm::vec3(0.0f), 1.0f);
	//text.props.font_size = 20.0f;
	//
	////m_text_ren->push(text);
}
