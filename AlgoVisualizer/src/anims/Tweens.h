#pragma once
#include <glm/glm.hpp>
#include <cmath>
#include <functional>

#include "Timer.h"

#define M_PI       3.14159265358979323846


namespace TWEENS
{
	static std::function<float(float, const float&)> LINEAR = 
		[](float t, const float& duration) { return t / duration; };


	static std::function<float(float, const float&)> EASE_IN_OUT = [](float t, const float& duration) {
		t /= duration;
		return 0.5 * (1.0 - std::cos(t * M_PI));
	};

}


class Tween
{
public:

	Tween(std::function<float(float, const float&)> func, const float& duration) 
		: m_timer(duration), m_tween_func(func) {}

	float update(const float& dt) {
		return m_tween_func(m_timer.update(dt), m_timer.getDuration());
	}

private:

	Timer m_timer;
	std::function<float(float, const float&)> m_tween_func;
};

