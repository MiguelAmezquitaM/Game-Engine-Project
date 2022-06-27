#pragma once

#include <vector>

namespace ecs
{
    class IEntity;

    template <class ComponentStorage_t, class... Entities_t>
    class EntityManager
    {
    public:
        template <typename T>
        using Container_t = std::vector<T>;
        using EntitiesContainer_t = std::tuple<Container_t<Entities_t>...>;
        using IEntitiesContainer_t = Container_t<IEntity *>;

        explicit EntityManager() : m_component_storage{} {}

        EntityManager(const EntityManager &) = delete;
        EntityManager(EntityManager &&) = delete;
        EntityManager &operator=(const EntityManager &) = delete;
        EntityManager &operator=(EntityManager &&) = delete;

        template <class Ent, class ContainerEnt = Container_t<Ent>>
        constexpr void reserve(Size_t __s) noexcept
        {
            std::get<ContainerEnt>(m_emtities).reserve(__s);
        }

        template <typename Ent_t, typename... Cmps, class TargetContainer = Container_t<Ent_t>>
        Ent_t &create_entity(Cmps &&...cmps)
        {
            auto &new_entity = std::get<TargetContainer>(m_emtities).emplace_back(m_component_storage.template addComponent<Cmps>(std::forward<Cmps>(cmps))...);
            m_pointer_entities.push_back(&new_entity);
            return new_entity;
        }

        template <typename Ent_t, class ContainerEnt = Container_t<Ent_t>>
        constexpr const ContainerEnt &get_entities() const noexcept
        {
            return std::get<ContainerEnt>(m_emtities);
        }

        template <typename Ent_t, class ContainerEnt = Container_t<Ent_t>>
        constexpr ContainerEnt &get_entities() noexcept
        {
            return std::get<ContainerEnt>(m_emtities);
        }

        constexpr const IEntitiesContainer_t &get_all_entities() const noexcept
        {
            return m_pointer_entities;
        }

        constexpr IEntitiesContainer_t &get_all_entities() noexcept
        {
            return m_pointer_entities;
        }

    private:
        EntitiesContainer_t m_emtities;
        IEntitiesContainer_t m_pointer_entities;
        ComponentStorage_t m_component_storage;
    };
} // namespace ecs
