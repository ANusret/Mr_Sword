#include "Character.h"
#include "raylib.h"
#include "raymath.h"
#include <string>

Character::Character(int windowWidth, int windowHeight, Texture2D idle, Texture2D run)
{
    this->texture = idle;
    this->idle = idle;
    this->run = run;
    screenPos = {
        static_cast<float>(windowWidth) / 2.0f - scale * (0.5f * width),
        static_cast<float>(windowHeight) / 2.0f - scale * (0.5f * height)};
    width = texture.width / maxFrame;
    height = texture.height;
}

void Character::tick(float dT)
{
    BaseCharacter::tick(dT);

    Vector2 direction{};
    if (IsKeyDown(KEY_A))
        direction.x -= 1.0;
    if (IsKeyDown(KEY_D))
        direction.x += 1.0;
    if (IsKeyDown(KEY_W))
        direction.y -= 1.0;
    if (IsKeyDown(KEY_S))
        direction.y += 1.0;
    if (Vector2Length(direction) != 0.0)
    {
        // set worldPos = worldPos + direction

        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(direction), speed));
        direction.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;
        texture = run;
    }
    else
    {
        texture = idle;
    }

}
