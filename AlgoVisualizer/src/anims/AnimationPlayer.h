#pragma once
#include <vector>
#include <glm/glm.hpp>
#include "Entity/Entity.h"
#include "anims/Tweens.h"
#include "anims/TransformAnimation.h"
#include "anims/ColorAnimation.h"
#include "anims/AnimationChain.h"


class AnimationPlayer
{
public:

	void play(const TransformAnimation& anim);
	void play(const ColorAnimation& anim);
	void play(AnimationChain* anim_chain);

	void onUpdate(const float& dt);

	void onUpdateTransform(const float& dt);
	void onUpdateColor(const float& dt);

private:

	std::vector<TransformAnimation> m_transform_anims;
	std::vector<ColorAnimation> m_color_anims;

};

