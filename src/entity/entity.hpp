#pragma once

#include <tuple>
#include <ientity.hpp>

namespace ecs
{

    template <class... Cmps>
    class Entity : public IEntity
    {
    public:
        Entity(Cmps &...cmps) : m_components(cmps...) {}

        template <class Cmp>
        Cmp &getComponent()
        {
            return std::get<Cmp &>(m_components);
        }

    private:
        std::tuple<Cmps &...> m_components;
    };

} // namespace ecs
