#pragma once
#include <algorithm>





class Timer
{
public:

	Timer(const float& duration) : m_time(0.0f), m_duration(duration) {}

	float update(const float& dt) {
		float val_before_update = m_time;

		m_time = std::min(m_time + dt, m_duration);

		return val_before_update;
	}

	const float& getDuration() {
		return m_duration;
	}

private:

	float m_time;
	float m_duration;

};

