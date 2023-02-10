#include "raylib.h"
#include "raymath.h"
#include "BaseCharacter.h"

BaseCharacter::BaseCharacter()
{
}

void BaseCharacter::undoMovement()
{
    worldPos = worldLastFrame;
}

Rectangle BaseCharacter::getRec()
{
    return Rectangle{
        screenPos.x,
        screenPos.y,
        width * scale,
        height * scale};
}

void BaseCharacter::tick(float dT)
{
    worldLastFrame = worldPos;

    
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
        scale * width,
        scale * height};
    Vector2 origin{0.0f, 0.0f};
    DrawTexturePro(texture, source, dest, origin, 0.0f, WHITE);
}
