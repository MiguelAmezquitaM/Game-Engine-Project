#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <exception>
#include <cstdio>
#include "glfw_window.hpp"

namespace ecs
{
    GLFWWindow::GLFWWindow(const WindowConfig &wg)
        : IWindow{wg} {}

    void GLFWWindow::start()
    {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

        if (!title)
        {
            finalize();
            std::terminate();
        }

        if (!glfwInit())
        {
            finalize();
            std::terminate();
        }

        if (fullscreen)
        {
            int xpos, ypos;
            GLFWmonitor *monitor = glfwGetPrimaryMonitor();
            glfwGetMonitorWorkarea(monitor, &xpos, &ypos, &width, &height);
            width += xpos;
            height += ypos;
            m_window = glfwCreateWindow(width, height, title, monitor, nullptr);
        }
        else
        {
            m_window = glfwCreateWindow(width, height, title, nullptr, nullptr);
        }

        if (!m_window)
        {
            finalize();
            std::terminate();
        }

        glfwMakeContextCurrent(m_window);

        if (glewInit() != GLEW_OK)
        {
            finalize();
            std::terminate();
        }

        glfwSetWindowAttrib(m_window, GLFW_RESIZABLE, resizable);
        glfwSetWindowAttrib(m_window, GLFW_MAXIMIZED, fullscreen);
    }

    void GLFWWindow::update(void *screen)
    {
        glfwPollEvents();
        glDrawPixels(width, height, GL_BGRA, GL_UNSIGNED_BYTE, screen);
        {
            static int width, height;
            glfwGetWindowSize(m_window, &width, &height);
        }
        glfwSwapBuffers(m_window);
    }

    void GLFWWindow::finalize()
    {
        if (m_window)
            glfwDestroyWindow(m_window);

        glfwTerminate();
    }

    bool GLFWWindow::is_open() const
    {
        return !glfwWindowShouldClose(m_window);
    }
} // namespace ecs
