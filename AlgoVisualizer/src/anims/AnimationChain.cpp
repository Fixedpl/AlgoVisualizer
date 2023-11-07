#include "AnimationChain.h"

std::vector<TransformAnimation>& AnimationChain::getTransformAnims()
{
	return m_transform_anims;
}

std::vector<ColorAnimation>& AnimationChain::getColorAnims()
{
	return m_color_anims;
}

AnimationChain::AnimationChain()
	: m_transform_delay(0.0f), m_color_delay(0.0f)
{
}

void AnimationChain::add(TransformAnimation transform_anim)
{
	transform_anim.time -= m_transform_delay;
	m_transform_anims.push_back(transform_anim);
	m_transform_delay += transform_anim.duration;
}

void AnimationChain::add(ColorAnimation color_anim)
{
	color_anim.time -= m_color_delay;
	m_color_anims.push_back(color_anim);
	m_color_delay += color_anim.duration;
}
