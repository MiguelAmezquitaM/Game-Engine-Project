#include <Engine.hpp>
#include <window/impls/glfw_window.hpp>
#include <managers/component_storage.hpp>
#include <managers/entity_manager.hpp>

using namespace ecs;

int main()
{
    WindowConfig wc{
        .title = "Game",
        .fullscreen = true,
    };



    Engine<GLFWWindow, EntityManager<ComponentStorage<>>, ComponentStorage<>> engine{wc};

    engine.start();
}

/**
 * 
 * 
 * 
 */