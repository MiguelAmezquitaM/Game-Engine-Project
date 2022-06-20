#pragma once

#include <cstdint>
#include <screen.hpp>

/* Forwar declarations */
class GLFWwindow;

namespace ecs
{

   struct WindowConfig
   {
   public:
      const char *title{"no named window"};
      uint32_t width{640}, height{360};
      bool fullscreen{false};
   };

   class Window
   {
   public:
      Window(WindowConfig &&window_config) noexcept;
      ~Window();

      void update();
      bool closed() const noexcept;

   private:
      GLFWwindow *m_window{ nullptr };
      std::unique_ptr<Screen> m_screen{ nullptr };
   };

}