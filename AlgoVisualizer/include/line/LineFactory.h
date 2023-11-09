#pragma once
#include <glm/glm.hpp>
#include "Entity/Entity.h"
#include "Entity/EntityRegistry.h"

#include "dll_algo.h"


class LineFactory
{
public:

	AV_API static Entity line(const glm::vec3& pos, const glm::vec3& line_vec, const glm::vec4& color, 
		const float& thickness, EntityRegistry* registry);

	AV_API static Entity rect(const glm::vec3& pos, const glm::vec3& line_vec, const glm::vec4& color,
		const float& thickness, EntityRegistry* registry);

};







