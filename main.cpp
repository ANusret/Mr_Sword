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
    Vector2 mapPos{0.0, 0.0};
    const float mapScale{4.0f};

    Character lord;
    lord.setScreenPos(windowWidth, windowHeight);

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        // get delta time
        float dT{GetFrameTime()};

        BeginDrawing();
        ClearBackground(WHITE);

        mapPos = Vector2Scale(lord.getWorldPos(), -1.f);

        // draw the map
        DrawTextureEx(Map, mapPos, 0.0, 4.0, WHITE);
        lord.tick(GetFrameTime());
        
        // check map bounds
        if (lord.getWorldPos().x < 0.f ||
            lord.getWorldPos().y < 0.f ||
            lord.getWorldPos().x + windowWidth > Map.width * mapScale ||
            lord.getWorldPos().y + windowHeight > Map.height * mapScale)
        {
            lord.undoMovement();
        }

        EndDrawing();
    }
    CloseWindow();
    UnloadTexture(Map);

    return 0;
}