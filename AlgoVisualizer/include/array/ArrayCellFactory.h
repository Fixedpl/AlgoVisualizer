#pragma once
#include <glm/glm.hpp>
#include "Entity/Entity.h"
#include "Entity/EntityRegistry.h"

#include "dll_algo.h"



class ArrayCellFactory
{
public:

	AV_API static Entity arrayCell(const std::string& text_str, const float& size,
		const glm::vec3& pos, EntityRegistry* registry);

	AV_API static void update(Entity& array_cell);
	AV_API static void updatePosition(Entity& array_cell);

	AV_API static Entity rect(EntityRegistry* registry, const glm::vec3& pos, const float& size);

	AV_API static Entity text(EntityRegistry* registry, const std::string& text_str, const glm::vec3& pos);

};

