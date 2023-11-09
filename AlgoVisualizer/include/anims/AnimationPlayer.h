#pragma once
#include <vector>
#include <glm/glm.hpp>
#include "Entity/Entity.h"
#include "anims/Tweens.h"
#include "anims/TransformAnimation.h"
#include "anims/ColorAnimation.h"
#include "anims/AnimationChain.h"

#include "dll_algo.h"


class AnimationPlayer
{
public:

	AV_API void play(const TransformAnimation& anim);
	AV_API void play(const ColorAnimation& anim);
	AV_API void play(AnimationChain* anim_chain);

	AV_API void onUpdate(const float& dt);

	AV_API void onUpdateTransform(const float& dt);
	AV_API void onUpdateColor(const float& dt);

private:

	std::vector<TransformAnimation> m_transform_anims;
	std::vector<ColorAnimation> m_color_anims;

};

