#pragma once
#include <Entity/Entity.h>
#include "dll.h"


class EntityRegistry
{
public:

    L4_API Entity createEntity();

    L4_API void destroyEntity(Entity& entity);

private:

    entt::registry m_registry;
};

