

#ifndef BASE_CHARACTER_H
#define BASE_CHARACTER_H
#include "raylib.h"

class BaseCharacter
{
public:
    BaseCharacter();
    Vector2 getWorldPos() { return worldPos; }
    void undoMovement();
    Rectangle getRec();
    virtual void tick(float dT);

protected:
    Texture texture{};
    Texture idle{};
    Texture run{};
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
private:
};

#endif