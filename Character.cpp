#include "Character.h"
#include "raylib.h"
#include "raymath.h"
#include <string>

Character::Character(int windowWidth,
                     int windowHeight,
                     Texture2D idle,
                     Texture2D run,
                     Texture2D weapon)
{
    this->texture = idle;
    this->idle = idle;
    this->run = run;
    width = texture.width / maxFrame;
    height = texture.height;
    this->windowWidth = windowWidth;
    this->windowHeight = windowHeight;
    this->weapon = weapon;
}

void Character::tick(float dT)
{
    if (!getAlive())
        return;

    if (IsKeyDown(KEY_A))
        velocity.x -= 1.0;
    if (IsKeyDown(KEY_D))
        velocity.x += 1.0;
    if (IsKeyDown(KEY_W))
        velocity.y -= 1.0;
    if (IsKeyDown(KEY_S))
        velocity.y += 1.0;

    BaseCharacter::tick(dT);

    Vector2 origin{};
    Vector2 offset{};
    float rotation{};
    if (rightLeft > 0.0f)
    {
        origin = {0.0f,
                  weapon.height * scale};
        offset = {40.0f, 55.0f};
        weaponColRec = {
            getScreenPos().x + offset.x,
            getScreenPos().y + offset.y - weapon.height * scale,
            weapon.width * scale,
            weapon.height * scale};
        rotation = IsMouseButtonDown(MOUSE_LEFT_BUTTON) ? 35.0f : 0.0f;
    }
    else
    {
        origin = {weapon.width * scale,
                  weapon.height * scale};
        offset = {25.0f, 55.0f};
        weaponColRec = {
            getScreenPos().x + offset.x - weapon.width * scale,
            getScreenPos().y + offset.y - weapon.height * scale,
            weapon.width * scale,
            weapon.height * scale};
        rotation = IsMouseButtonDown(MOUSE_LEFT_BUTTON) ? -30.0f : 0.0f;
    }

    Rectangle source = {0.0f,
                        0.0f,
                        static_cast<float>(weapon.width) * rightLeft,
                        static_cast<float>(weapon.height)};

    Rectangle dest = {getScreenPos().x + offset.x,
                      getScreenPos().y + offset.y,
                      weapon.width * scale,
                      weapon.height * scale};

    // draw the sword
    DrawTexturePro(weapon,
                   source,
                   dest,
                   origin,
                   rotation,
                   WHITE);
/*
    // weapon collision rectangle, this rectangle like hitbox
    DrawRectangleLines(
        weaponColRec.x,
        weaponColRec.y,
        weaponColRec.width,
        weaponColRec.height,
        RED);
*/
}

Vector2 Character::getScreenPos()
{
    return Vector2{static_cast<float>(windowWidth) / 2.0f - scale * (0.5f * width),
                   static_cast<float>(windowHeight) / 2.0f - scale * (0.5f * height)};
}

void Character::takeDamage(float damage)
{
    health -= damage;
    if (health <= 0.0f)
    {
        setAlive(false);
    }
    
}
