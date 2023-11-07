#pragma once
#include <memory>

#include "Test/Test.h"

#include "circle/CircleRenderer.h"
#include "rectangle/RectangleRenderer.h"
#include "text/TextRenderer.h"

struct Node
{
	glm::vec3 pos;
	std::string text;
};


class RenderersTest : public Test
{
public:

	RenderersTest(Window* window);

	void onUpdate(const float& frame_time);

	void onImGuiUpdate();

private:

	void push(const Node& node);

private:

	std::unique_ptr<CircleRenderer> m_circles_ren;
	std::unique_ptr<RectangleRenderer> m_rect_ren;
	std::unique_ptr<TextRenderer> m_text_ren;

	glm::mat4 m_mvp;

	Node node1;
	Node node2;
};
