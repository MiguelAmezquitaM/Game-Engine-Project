#pragma once

#include <tuple>

namespace ecs
{

    class IEntity
    {
    public:
        virtual void update() = 0;
    };

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
