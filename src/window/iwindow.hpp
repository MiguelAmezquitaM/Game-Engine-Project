#pragma once

#include <util/types.hpp>
#include <type_traits>

namespace ecs
{
   struct WindowConfig
   {
      char const *title{"Unnamed"};
      int width{640};
      int height{360};
      bool fullscreen{false};
      bool resizable{false};
   };

   class IWindow : public WindowConfig
   {
   public:
      explicit IWindow(const WindowConfig &wg)
          : WindowConfig{wg} {}

      void start();
      void update(void *);
      void finalize();
      bool is_open() const;
   };

   template<class WinT>
   concept WindowC = std::is_base_of_v<IWindow, WinT>;
} // namespace ecs
