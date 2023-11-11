#pragma once
#include <memory>

#include "Test/Test.h"
#include "line/LineRenderer.h"
#include "Entity/Entity.h"
#include "Entity/EntityRegistry.h"
#include "BaseComponents.h"






class LineTest : public Test
{
public:

	LineTest(Window* window);

protected:

	void onUpdate(const float& dt);

	void onImGuiUpdate();

private:

	std::unique_ptr<LineRenderer> m_line_ren;;

	glm::mat4 m_mvp;

	EntityRegistry registry;
	Entity line;
	Transform* transform;
	Border* border;
	Color* color;
	LineProps* props;

	LineBufferArray* buffer;
};

