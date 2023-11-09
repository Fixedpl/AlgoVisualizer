#pragma once
#include <glm/glm.hpp>
#include "Entity/Entity.h"




struct ColorAnimation
{
	ColorAnimation(Entity& entity, const float& duration, const float& time,
		const glm::vec4& beg_color, const glm::vec4& end_color, 
		std::function<float(float, const float&)>& func)
		: entity(entity), duration(duration), time(time), beg_color(beg_color), 
		end_color(end_color), func(func) {}

	ColorAnimation& operator=(const ColorAnimation& other) {
		entity = other.entity;
		duration = other.duration;
		time = other.time;
		beg_color = other.beg_color;
		end_color = other.end_color;
		func = other.func;
		return *this;
	}

	Entity& entity;
	float duration;
	float time;
	glm::vec4 beg_color;
	glm::vec4 end_color;
	std::function<float(float, const float&)>& func;
};

