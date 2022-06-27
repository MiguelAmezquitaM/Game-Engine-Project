#pragma once
#include <window/iwindow.hpp>
#include <entity/entities/screen.hpp>

namespace ecs
{

    template <WindowC Window_t, class EntityMan_t, class CmpMan_t>
    class Engine
    {
    public:
        Engine(const WindowConfig &wc)
            : m_window{wc} {}

        void start()
        {
            m_window.start();

            static Screen screen(m_window.width, m_window.height);

            while (m_window.is_open())
            {
                m_window.update(screen.pixels);
            }

            m_window.finalize();
        }

    private:
        Window_t m_window;
        EntityMan_t m_entman;
        CmpMan_t m_cmpman;
    };
} // namespace ecs
