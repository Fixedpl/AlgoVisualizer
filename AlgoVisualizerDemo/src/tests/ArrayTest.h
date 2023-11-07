#pragma once
#include <memory>

#include "Test/Test.h"
#include "text/TextRenderer.h"
#include "rectangle/RectangleRenderer.h"
#include "anims/Tweens.h"
#include "Entity/Entity.h"
#include "Entity/EntityRegistry.h"
#include "array/ArrayGG.h"
#include "anims/AnimationPlayer.h"


class ArrayTest : public Test
{
public:

	ArrayTest(Window* window);

	void onUpdate(const float& frame_time);
	void onImGuiUpdate();

private:

	std::unique_ptr<TextRenderer> m_text_ren;
	std::unique_ptr<RectangleRenderer> m_rect_ren;

	glm::vec3 m_array_position;

	Tween* m_tween;

	Entity array_cell;
	Entity array;
	ArrayBuffer array_buffer;

	AnimationPlayer m_anim_player;

	EntityRegistry m_registry;

	glm::mat4 m_mvp;
};

