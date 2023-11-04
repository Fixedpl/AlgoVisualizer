#pragma once
#include <glm/glm.hpp>
#include <cmath>
#include <functional>

#include "Timer.h"

#define M_PI       3.14159265358979323846

// https://easings.net/
namespace TWEENS
{
	static std::function<float(float, const float&)> LINEAR = 
		[](float t, const float& duration) { return t / duration; };


	static std::function<float(float, const float&)> EASE_IN_OUT_SIN = [](float t, const float& duration) {
		t /= duration;
		return -(std::cos(M_PI * t) - 1) / 2.0f;
	};

	static std::function<float(float, const float&)> EASE_IN_OUT_QUAD = [](float t, const float& duration) {
		t /= duration;
		return t < 0.5f ? 2 * t * t : 1 - std::pow(-2 * t + 2, 2) / 2.0f;
	};

	static std::function<float(float, const float&)> EASE_IN_OUT_CUBIC = [](float t, const float& duration) {
		t /= duration;
		return t < 0.5f ? 4 * t * t * t : 1 - std::pow(-2 * t + 2, 3) / 2.0f;
	};

	static std::function<float(float, const float&)> EASE_IN_OUT_QUART = [](float t, const float& duration) {
		t /= duration;
		return t < 0.5f ? 8 * t * t * t * t : 1 - std::pow(-2 * t + 2, 4) / 2.0f;
	};

	static std::function<float(float, const float&)> EASE_IN_OUT_BACK = [](float t, const float& duration) {
		t /= duration;
		float c1 = 1.70158f;
		float c2 = c1 * 1.525f;

		return t < 0.5f
			? (std::pow(2 * t, 2) * ((c2 + 1) * 2 * t - c2)) / 2.0f
			: (std::pow(2 * t - 2, 2) * ((c2 + 1) * (t * 2 - 2) + c2) + 2) / 2.0f;
	};

	static std::function<float(float, const float&)> EASE_IN_OUT_ELASTIC = [](float t, const float& duration) {
		t /= duration;
		float c5 = (2 * M_PI) / 4.5f;

		return t == 0.0f ? 0.0f
			: t == 1.0f
			? 1.0f
			: t < 0.5f
			? -(std::pow(2, 20 * t - 10) * std::sin((20 * t - 11.125f) * c5)) / 2.0f
			: (std::pow(2, -20 * t + 10) * std::sin((20 * t - 11.125f) * c5)) / 2.0f + 1;
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

