#pragma once
#include "anims/TransformAnimation.h"
#include "anims/ColorAnimation.h"
#include "anims/AnimationChain.h"


class AnimationChainBuilder
{
public:

	AnimationChainBuilder(Entity& entity);

	AnimationChainBuilder& move(std::function<float(float, const float&)>& tween,
		const float& duration, const glm::vec3& vec);

	AnimationChainBuilder& color(std::function<float(float, const float&)>& tween,
		const float& duration, const glm::vec4& beg_color, const glm::vec4& end_color);

	AnimationChain* build();

private:

	Entity& m_entity;
	AnimationChain* m_anim_chain;
};

