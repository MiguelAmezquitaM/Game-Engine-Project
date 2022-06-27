#pragma once

namespace ecs
{
    class IEntity
    {
    public:
        void start();
        void update();
        void finalize();
    };
} // namespace ecs
