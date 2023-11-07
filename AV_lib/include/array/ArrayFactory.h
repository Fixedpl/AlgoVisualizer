#pragma once
#include <glm/glm.hpp>
#include "Entity/Entity.h"
#include "Entity/EntityRegistry.h"

#include "dll_algo.h"


class ArrayFactory
{
public:

	AV_API static Entity array(const std::vector<std::string>& texts, const float& cell_size,
		const glm::vec3& pos, EntityRegistry* registry);

	AV_API static void update(Entity& array);
	AV_API static void updatePosition(Entity& array);

};

