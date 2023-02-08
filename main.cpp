#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include <string>


int main()
{
    const int windowHeight{512};
    const int windowWidth{512};
    InitWindow(windowWidth, windowHeight, "Mr. Sword");

    Texture2D Map = LoadTexture("Map/WorldMap.png");

    Character lord;
    lord.setScreenPos(windowWidth, windowHeight);

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        // get delta time
        float dT{GetFrameTime()};

        BeginDrawing();
        ClearBackground(WHITE);

        // draw map
        DrawTextureEx(Map, lord.getWorldPos(), 0.0f, 4.0f, WHITE);

        lord.tick(dT);

        EndDrawing();
    }
    CloseWindow();
    UnloadTexture(Map);

    return 0;
}

/*
Texture2D Map = LoadTexture("Map/WorldMap.png");
    Vector2 mapPos{0.0, 0.0};
    float speed{2.0f};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        Vector2 direction{};
        if (IsKeyDown(KEY_A))
            direction.x -= 1.0f;
        if (IsKeyDown(KEY_D))
            direction.x += 1.0f;
        if (IsKeyDown(KEY_W))
            direction.y -= 1.0f;
        if (IsKeyDown(KEY_S))
            direction.y += 1.0f;
        if (Vector2Length(direction) != 0.0f)
        {
            mapPos = Vector2Subtract(mapPos, Vector2Scale(Vector2Normalize(direction), speed));
        }
*/
