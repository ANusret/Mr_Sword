#include "Character.h"
#include "raylib.h"
#include "raymath.h"
#include <string>


void Character::setScreenPos(int windowWidth, int windowHeight)
{
    screenPos = {
        (float)windowWidth / 2.0f - 4.0f * (0.5f * (float)texture.width / 6.0f),
        (float)windowHeight / 2.0f - 4.0f * (0.5f * (float)texture.height)};
}

void Character::tick(float dT)
{
    texture = idle;
    if (IsKeyDown(KEY_W))
    {
        worldPos = Vector2Add(worldPos, vectorU);
        texture = run;
    }
    if (IsKeyDown(KEY_S))
    {
        worldPos = Vector2Add(worldPos, vectorD);
        texture = run;
    }
    if (IsKeyDown(KEY_D))
    {
        worldPos = Vector2Add(worldPos, vectorR);
        rightLeft = 1.0f;
        texture = run;
    }
    if (IsKeyDown(KEY_A))
    {
        worldPos = Vector2Add(worldPos, vectorL);
        rightLeft = -1.0f;
        texture = run;
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
        frame * (float)texture.width / 6.0f,
        0.0f,
        rightLeft * (float)texture.width / 6.0f,
        (float)texture.height};
    Rectangle dest{
        screenPos.x,
        screenPos.y,
        4.0f * (float)texture.width / 6.0f,
        4.0f * (float)texture.height};
    Vector2 origin{0.0f, 0.0f};
    DrawTexturePro(texture, source, dest, origin, 0.0f, WHITE);
}
