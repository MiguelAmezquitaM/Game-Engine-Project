#pragma once

#include <memory>
#include <cstdint>

namespace ecs
{
    class Screen
    {
    public:
        explicit Screen(uint16_t width, uint16_t height)
            : height{height}, width{width}, pixels{std::make_unique<uint32_t[]>(width * height)} {}

        Screen(const Screen &) = delete;
        Screen(const Screen &&) = delete;
        Screen &operator=(const Screen &) = delete;
        Screen &operator=(const Screen &&) = delete;

        uint16_t height, width;
        std::unique_ptr<uint32_t[]> pixels;
    };
} // namespace ecs
