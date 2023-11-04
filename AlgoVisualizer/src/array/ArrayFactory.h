#pragma once
#include <glm/glm.hpp>
#include "Entity/Entity.h"
#include "Entity/EntityRegistry.h"
#include "text/Font.h"





class ArrayFactory
{
public:

	static Entity array(const std::vector<std::string>& texts, const float& cell_size, const glm::vec3& pos,
		Font* font, EntityRegistry* registry);

	static void update(Entity& array);
	static void updatePosition(Entity& array);

};

