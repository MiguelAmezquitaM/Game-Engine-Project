#pragma once
#include <window/iwindow.hpp>

/* Forward declarations */
class GLFWwindow;

namespace ecs
{
    class GLFWWindow : public IWindow
    {
    public:
        GLFWWindow(const WindowConfig &wc);

        void start();
        void update(void *screen);
        void finalize();
        bool is_open() const;

    private:
        GLFWwindow *m_window{nullptr};
    };
} // namespace ecs
