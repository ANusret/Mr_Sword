#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include "Enemy.h"
#include "prop.h"
#include <string>

int main()
{
    const int windowHeight{512};
    const int windowWidth{512};
    InitWindow(windowWidth, windowHeight, "Mr. Sword");

    Texture2D Map = LoadTexture("Map/WorldMap.png");
    Vector2 mapPos{0.0, 0.0};
    const float mapScale{4.0f};

    Character lord(windowWidth, windowHeight, LoadTexture("Characters/lord_idle_spritesheet.png"), LoadTexture("Characters/lord_run_spritesheet.png"));
    Prop rock(Vector2{400.0f, 350.0f}, LoadTexture("Textures/Rock.png"));

    // draw props
    Prop props[] = {
        rock,
        Prop{Vector2{800.0f, 850.0f}, LoadTexture("Textures/Log.png")}};

    Enemy goblin(Vector2{}, LoadTexture("Characters/goblin_idle_spritesheet.png"), LoadTexture("Characters/goblin_run_spritesheet.png"));

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
        lord.tick(dT);

        for (auto prop : props)
        {
            prop.Render(lord.getWorldPos());
        }

        goblin.tick(dT);

        // check map bounds
        if (lord.getWorldPos().x < 0.f ||
            lord.getWorldPos().y < 0.f ||
            lord.getWorldPos().x + windowWidth > Map.width * mapScale ||
            lord.getWorldPos().y + windowHeight > Map.height * mapScale)
        {
            lord.undoMovement();
        }

        // check prop collisions
        for (auto prop : props)
        {
            if (CheckCollisionRecs(prop.getPropRec(lord.getWorldPos()), lord.getRec()))
            {
                lord.undoMovement();
            }
        }

        EndDrawing();
    }
    CloseWindow();
    UnloadTexture(Map);

    return 0;
}