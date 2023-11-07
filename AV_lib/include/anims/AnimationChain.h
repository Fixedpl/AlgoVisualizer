#pragma once
#include "TransformAnimation.h"
#include "ColorAnimation.h"

#include "dll_algo.h"




class AnimationChain
{
public:

	AV_API AnimationChain();

	AV_API void add(TransformAnimation transform_anim);
	AV_API void add(ColorAnimation color_anim);

	AV_API std::vector<TransformAnimation>& getTransformAnims();

	AV_API std::vector<ColorAnimation>& getColorAnims();

private:

	std::vector<TransformAnimation> m_transform_anims;
	std::vector<ColorAnimation> m_color_anims;

	float m_transform_delay;
	float m_color_delay;

};

