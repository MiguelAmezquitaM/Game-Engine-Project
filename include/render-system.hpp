#pragma once

#include <screen.hpp>

namespace ecs
{

    class RenderSystem
    {
    public:
        RenderSystem(Screen &scr) : screen{scr} {}

        void update()
        {
        }

    private:
        Screen &screen;
    };

} // namespace ecs
