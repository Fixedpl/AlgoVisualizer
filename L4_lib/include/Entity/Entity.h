#pragma once
#include <cstdint>
#include <memory>

#include <entt/entt.hpp>

#include "dll.h"


class Entity
{
public:

    L4_API Entity() : m_entity((entt::entity)0), m_registry(nullptr) {}
    L4_API Entity(entt::registry* registry, entt::entity entity) : m_registry(registry), m_entity(entity) {}

    template <typename T, typename... Args>
    void add(Args&&... args) {
        m_registry->emplace<T>(m_entity, std::forward<Args>(args)...);
    }

    template <typename T>
    T& get() {
        return m_registry->get<T>(m_entity);
    }

    template <typename T>
    const T& get() const {
        return m_registry->get<T>(m_entity);
    }

    template <typename T>
    void remove() {
        m_registry->remove<T>(m_entity);
    }

    template <typename T>
    bool has() {
        return m_registry->any_of<T>(m_entity);
    }

    L4_API entt::entity getNativeEntity() {
        return m_entity;
    }

private:

    entt::entity m_entity;
    entt::registry* m_registry;
};

