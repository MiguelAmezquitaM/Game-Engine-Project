#pragma once

#include <types.hpp>

namespace ecs
{
    template <class... Components_t>
    class ComponentStorage
    {
    public:
        ComponentStorage() = default;

        ComponentStorage(const ComponentStorage &) = delete;
        ComponentStorage(const ComponentStorage &&) = delete;
        ComponentStorage &operator=(const ComponentStorage &) = delete;
        ComponentStorage &operator=(const ComponentStorage &&) = delete;

        template <class Comp, typename... Args>
        constexpr Comp &createComponent(Args &&...args) noexcept
        {
            return std::get<Container_t<Comp>>(m_components).emplace_back(args...);
        }

        template <class Comp>
        constexpr Comp &addComponent(Comp &&cmp) noexcept
        {
            Container_t<Comp>& cmps = std::get<Container_t<Comp>>(m_components);
            cmps.push_back(cmp);
            return cmps.back();
        }

        template <class Cmp>
        constexpr auto &getComponents() noexcept
        {
            return std::get<Container_t<Cmp>>(m_components);
        }

    private:
        std::tuple<Container_t<Components_t>...> m_components;
    };
} // namespace ecs
