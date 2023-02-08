#include "raylib.h"
#include "raymath.h"
#include <string>

class Character
{
public:
    Vector2 getWorldPos() { return worldPos; }
    void setScreenPos(int windowWidth, int windowHeight);
    void tick(float dT);

private:
    Texture texture{LoadTexture("Characters/lord_idle_spritesheet.png")};
    Texture idle{LoadTexture("Characters/lord_idle_spritesheet.png")};
    Texture run{LoadTexture("Characters/lord_run_spritesheet.png")};
    Vector2 screenPos{};
    Vector2 worldPos{};
    // looking right: 1 or looking left: -1
    float rightLeft{1.0f};
    const float speed{2.0f};
    Vector2 vectorU{0.0f, speed};
    Vector2 vectorD{0.0f, -speed};
    Vector2 vectorR{-speed, 0.0f};
    Vector2 vectorL{speed, 0.0f};

    // animation variables
    float runningTime{};
    float frame{};
    const int maxFrame{6};
    const float updateTime{1.0f / 12.0f};
};