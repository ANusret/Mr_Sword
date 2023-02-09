#include "raylib.h"
#include "raymath.h"
#include <string>

class Character
{
public:
    Character(int windowWidth, int windowHeight);
    Vector2 getWorldPos() { return worldPos; }
    void tick(float dT);
    void undoMovement();
    Rectangle getCharacterRec();
private:
    Texture texture{LoadTexture("Characters/lord_idle_spritesheet.png")};
    Texture idle{LoadTexture("Characters/lord_idle_spritesheet.png")};
    Texture run{LoadTexture("Characters/lord_run_spritesheet.png")};
    Vector2 screenPos{};
    Vector2 worldPos{};
    // last possition frame on the world
    Vector2 worldLastFrame{};
    // looking right: 1 or looking left: -1
    float rightLeft{1.0f};
    float speed{3.0f};
    Vector2 vectorU{0.0f, speed};
    Vector2 vectorD{0.0f, -speed};
    Vector2 vectorR{-speed, 0.0f};
    Vector2 vectorL{speed, 0.0f};

    // animation variables
    float runningTime{};
    float frame{};
    int maxFrame{6};
    float updateTime{1.0f / 12.0f};
    float width{};
    float height{};
    float scale{4.0f};
};