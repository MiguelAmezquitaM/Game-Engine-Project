#include <window.hpp>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <exception>
#include <algorithm>

namespace ecs
{
    Window::Window(WindowConfig &&wc) noexcept
    {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

        if (!wc.title)
        {
            std::terminate();
        }

        if (!glfwInit())
        {
            glfwTerminate();
            std::terminate();
        }

        if (wc.fullscreen)
        {
            int width_monitor, height_monitor;

            auto monitor = glfwGetPrimaryMonitor();
            glfwGetMonitorWorkarea(monitor, nullptr, nullptr, &width_monitor, &height_monitor);
            m_window = glfwCreateWindow(width_monitor, height_monitor, wc.title, monitor, nullptr);
            m_screen = std::make_unique<Screen>(width_monitor, height_monitor);
        }
        else
        {
            m_window = glfwCreateWindow(wc.width, wc.height, wc.title, nullptr, nullptr);
            m_screen = std::make_unique<Screen>(wc.width, wc.height);
        }

        if (!m_window)
        {
            glfwTerminate();
            std::terminate();
        }

        glfwMakeContextCurrent(m_window);

        if (glewInit() != GLEW_OK)
        {
            this->~Window();
            std::terminate();
        }
    }

    Window::~Window()
    {
        glfwDestroyWindow(m_window);
        glfwTerminate();
    }

    void Window::update()
    {
        glfwPollEvents();
        glDrawPixels(m_screen->width, m_screen->height, GL_BGRA, GL_UNSIGNED_BYTE, m_screen->pixels.get());
        glfwSwapBuffers(m_window);
    }

    bool Window::closed() const noexcept
    {
        return glfwWindowShouldClose(m_window);
    }
} // namespace ecs
