#pragma once
#include "Test/Test.h"
#include "text/TextRenderer.h"
#include "circle/CircleRenderer.h"
#include "Entity/Entity.h"
#include "Entity/EntityRegistry.h"
#include "node/NodeGG.h"




class NodeTest : public Test
{
public:

	NodeTest(Window* window);

	void onUpdate(const float& frame_time);
	void onImGuiUpdate();

private:

	std::unique_ptr<TextRenderer> m_text_ren;
	std::unique_ptr<CircleRenderer> m_circle_ren;

	glm::mat4 m_mvp;

	EntityRegistry registry;
	Entity node;
	Transform* transform;
	Color* color;
	NodeProps* props;
	CircleProps* circle_props;
	NodeBuffer buffer;
};

