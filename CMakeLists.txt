cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "-O3")

project(GameEngine VERSION 1.0.0)

include_directories(include deps)

add_executable (
    ${PROJECT_NAME}
    deps/libimgui.a
    src/window.cpp
    src/main.cpp
)

set( CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -pedantic --pedantic-errors --no-exceptions -O3" )

target_link_libraries(${PROJECT_NAME} GL glfw GLEW X11 Xext)
