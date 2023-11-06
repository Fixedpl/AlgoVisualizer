#pragma once
#include "TransformAnimation.h"
#include "ColorAnimation.h"






class AnimationChain
{
public:

	AnimationChain() : m_transform_delay(0.0f), m_color_delay(0.0f) {}

	void add(TransformAnimation transform_anim);
	void add(ColorAnimation color_anim);

	std::vector<TransformAnimation>& getTransformAnims() {
		return m_transform_anims;
	}

	std::vector<ColorAnimation>& getColorAnims() {
		return m_color_anims;
	}

private:

	std::vector<TransformAnimation> m_transform_anims;
	std::vector<ColorAnimation> m_color_anims;

	float m_transform_delay;
	float m_color_delay;

};

