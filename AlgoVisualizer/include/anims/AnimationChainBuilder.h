#pragma once
#include "anims/TransformAnimation.h"
#include "anims/ColorAnimation.h"
#include "anims/AnimationChain.h"

#include "dll_algo.h"


class AnimationChainBuilder
{
public:

	AV_API AnimationChainBuilder(Entity& entity);

	AV_API AnimationChainBuilder& move(std::function<float(float, const float&)>& tween,
		const float& duration, const glm::vec3& vec);

	AV_API AnimationChainBuilder& color(std::function<float(float, const float&)>& tween,
		const float& duration, const glm::vec4& beg_color, const glm::vec4& end_color);

	AV_API AnimationChain* build();

private:

	Entity& m_entity;
	AnimationChain* m_anim_chain;
};

