#pragma once
#include <memory>

#include "Tests/Test.h"
#include "text/TextRenderer.h"
#include "rectangle/RectangleRenderer.h"
#include "array/Array.h"
#include "anims/Tweens.h"


class ArrayTest : public Test
{
public:

	ArrayTest(Window* window);

	void onUpdate(const float& frame_time);
	void onImGuiUpdate();

private:

	std::unique_ptr<TextRenderer> m_text_renderer;
	std::unique_ptr<RectangleRenderer> m_rect_ren;

	Array* m_array;
	glm::vec3 m_array_position;

	Tween* m_tween;

	glm::mat4 m_mvp;
};

