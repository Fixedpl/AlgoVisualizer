#pragma once
#include <glm/glm.hpp>
#include "Entity/Entity.h"
#include "Entity/EntityRegistry.h"




class ArrayFactory
{
public:

	static Entity array(const std::vector<std::string>& texts, const float& cell_size, 
		const glm::vec3& pos, EntityRegistry* registry);

	static void update(Entity& array);
	static void updatePosition(Entity& array);

};

