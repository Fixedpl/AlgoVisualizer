#pragma once
#include <glm/glm.hpp>
#include "Entity/Entity.h"
#include "Entity/EntityRegistry.h"
#include "text/Font.h"





class ArrayCellFactory
{
public:

	static Entity arrayCell(const std::string& text_str, const float& size, const glm::vec3& pos, 
		Font* font, EntityRegistry* registry);

	static void update(Entity& array_cell);
	static void updatePosition(Entity& array_cell);

	static Entity rect(EntityRegistry* registry, const glm::vec3& pos, const float& size);

	static Entity text(EntityRegistry* registry, const std::string& text_str, const glm::vec3& pos, Font* font);

};

