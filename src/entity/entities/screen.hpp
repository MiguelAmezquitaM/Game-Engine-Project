#pragma once

#include <vector>
#include <cstdint>

namespace ecs
{
    class Screen
    {
    public:
        explicit Screen(uint16_t width, uint16_t height)
            : height{height}, width{width}, pixels{}, m_pixels{}
        {
            m_pixels.resize(width * height);
            pixels = m_pixels.data();
        }

        Screen(const Screen &) = delete;
        Screen(Screen &&) = delete;
        Screen &operator=(const Screen &) = delete;
        Screen &operator=(Screen &&) = delete;

        const uint16_t height, width;
        uint32_t *pixels;

    private:
        std::vector<uint32_t> m_pixels;
    };
} // namespace ecs
