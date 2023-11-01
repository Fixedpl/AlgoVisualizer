#pragma once
#include <Entity.h>



class EntityRegistry
{
public:

    Entity createEntity();

    void destroyEntity(Entity& entity);

private:

    entt::registry m_registry;
};

