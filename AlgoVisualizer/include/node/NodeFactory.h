#pragma once
#include <glm/glm.hpp>
#include "Entity/Entity.h"
#include "Entity/EntityRegistry.h"

#include "dll_algo.h"


class NodeFactory
{
public:

	AV_API static Entity node(const std::string& text_str, const float& radius, const glm::vec4& color,
		const glm::vec3& pos, EntityRegistry* registry);

	AV_API static void update(Entity& node);
	AV_API static void updatePosition(Entity& node);

	AV_API static Entity circle(EntityRegistry* registry, const glm::vec3& pos, const float& radius, const glm::vec4& color);

	AV_API static Entity text(EntityRegistry* registry, const std::string& text_str, const glm::vec3& pos);

};

