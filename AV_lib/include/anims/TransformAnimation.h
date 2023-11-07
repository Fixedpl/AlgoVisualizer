#pragma once
#include <glm/glm.hpp>
#include "Entity/Entity.h"



struct TransformAnimation
{

	TransformAnimation(Entity& entity, const float& duration, const float& time,
		const glm::vec3& vec, std::function<float(float, const float&)>& func)
		: entity(entity), duration(duration), time(time), vec(vec), moved_by(0.0f), func(func) {}

	TransformAnimation& operator=(const TransformAnimation& other) {
		entity = other.entity;
		duration = other.duration;
		time = other.time;
		moved_by = other.moved_by;
		vec = other.vec;
		func = other.func;
		return *this;
	}

	Entity& entity;
	float duration;
	float time;
	glm::vec3 moved_by;
	glm::vec3 vec;
	std::function<float(float, const float&)>& func;
};
