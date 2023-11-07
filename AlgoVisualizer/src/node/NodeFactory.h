#pragma once
#include <glm/glm.hpp>
#include "Entity/Entity.h"
#include "Entity/EntityRegistry.h"




class NodeFactory
{
public:

	static Entity node(const std::string& text_str, const float& radius, const glm::vec4& color, 
		const glm::vec3& pos, EntityRegistry* registry);

	static void update(Entity& node);
	static void updatePosition(Entity& node);

	static Entity circle(EntityRegistry* registry, const glm::vec3& pos, const float& radius, const glm::vec4& color);

	static Entity text(EntityRegistry* registry, const std::string& text_str, const glm::vec3& pos);

};

