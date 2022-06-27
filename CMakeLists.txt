cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_CXX_COMPILER /usr/bin/g++-11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "-O3")

project(GameEngine VERSION 1.0.0)

include_directories(src include deps)

add_executable (
    ${PROJECT_NAME}
    src/main.cpp
    src/window/impls/glfw_window.cpp
)

set( CMAKE_CXX_FLAGS "-std=c++20 -O3 -Wall -Wextra -Werror -pedantic --pedantic-errors -fno-exceptions" )

target_link_libraries(${PROJECT_NAME} GL glfw GLEW)
