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
        getScreenPos().x,
        getScreenPos().y,
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

    if (Vector2Length(velocity) != 0.0)
    {
        // set worldPos = worldPos + direction

        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(velocity), speed));
        velocity.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;
        texture = run;
    }
    else
    {
        texture = idle;
    }

    velocity = {};

    // draw character
    Rectangle source{
        frame * width,
        0.0f,
        rightLeft * width,
        height};
    Rectangle dest{
        getScreenPos().x,
        getScreenPos().y,
        scale * width,
        scale * height};
    Vector2 origin{0.0f, 0.0f};
    DrawTexturePro(texture, source, dest, origin, 0.0f, WHITE);
}
