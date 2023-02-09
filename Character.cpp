#include "Character.h"
#include "raylib.h"
#include "raymath.h"
#include <string>

Character::Character()
{
    width = texture.width / maxFrame;
    height = texture.height;
}

void Character::setScreenPos(int windowWidth, int windowHeight)
{
    screenPos = {
        (float)windowWidth / 2.0f - 4.0f * (0.5f * width),
        (float)windowHeight / 2.0f - 4.0f * (0.5f * height)};
}

void Character::tick(float dT)
{

    worldLastFrame = worldPos;
    
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
    
    // update animation frame
    runningTime += dT;
    if (runningTime >= updateTime)
    {
        frame++;
        runningTime = 0.0f;
        if (frame > maxFrame)
            frame = 0;
    }

    // draw character
    Rectangle source{
        frame * width,
        0.0f,
        rightLeft * width,
        height};
    Rectangle dest{
        screenPos.x,
        screenPos.y,
        4.0f * width,
        4.0f * height};
    Vector2 origin{0.0f, 0.0f};
    DrawTexturePro(texture, source, dest, origin, 0.0f, WHITE);
}

void Character::undoMovement()
{
    worldPos = worldLastFrame;
}