#include <window.hpp>

using namespace ecs;

int main() noexcept
{
    Window win{
        WindowConfig{
            .title = "My app",
            .fullscreen = true,
        }};

    while (!win.closed())
    {
        win.update();
    }

    return 0;
}

/*

















 class PhysicsComponent
{
public:
    PhysicsComponent(int16_t x, int16_t y, uint16_t width, uint16_t height)
        : x{x}, y{y}, width{width}, height{height} {}
    int16_t x, y;
    uint16_t width, height;
};

class HealthComponent
{
public:
    HealthComponent(uint8_t initial_health)
        : heal{initial_health} {}
    uint8_t heal;
};

class Player : public Entity<PhysicsComponent, HealthComponent>
{
public:
    template <class... Cmps>
    Player(Cmps &...cmps) : Entity(cmps...) {}

    ~Player() {}

    void update() override
    {
        auto &phy = getComponent<PhysicsComponent>();
        auto &heal = getComponent<HealthComponent>();
        printf("x: %d, y: %d\n", phy.x, phy.y);
        printf("width: %d, height: %d\n", phy.width, phy.height);
        printf("heal: %d\n", heal.heal);
    }
}; */

/* class Enemy : public Entity<PhysicsComponent, HealthComponent>
{
public:
    template <class... Cmps>
    Enemy(Cmps &...cmps) : Entity(cmps...) {}

    ~Enemy() {}

    void update() override
    {
        auto &phy = getComponent<PhysicsComponent>();
        auto &heal = getComponent<HealthComponent>();
        printf("x: %d, y: %d\n", phy.x, phy.y);
        printf("width: %d, height: %d\n", phy.width, phy.height);
        printf("heal: %d\n", heal.heal);
    }
}; */