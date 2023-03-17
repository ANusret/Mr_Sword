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

    Character lord(windowWidth,
                   windowHeight,
                   LoadTexture("Characters/lord_idle_spritesheet.png"),
                   LoadTexture("Characters/lord_run_spritesheet.png"),
                   LoadTexture("Characters/weapon_sword.png"));
    Prop rock(Vector2{400.0f, 350.0f}, LoadTexture("Textures/Rock.png"));

    // draw props
    Prop props[] = {
        rock,
        Prop{Vector2{800.0f, 850.0f}, LoadTexture("Textures/Log.png")}};

    Enemy goblin1(Vector2{2400.0f, 2400.0f},
                  LoadTexture("Characters/goblin_idle_spritesheet.png"),
                  LoadTexture("Characters/goblin_run_spritesheet.png"));

    Enemy slime1(Vector2{500.0f, 500.0f},
                 LoadTexture("Characters/slime_idle_spritesheet.png"),
                 LoadTexture("Characters/slime_run_spritesheet.png"));

    Enemy goblin2(Vector2{800.0f, 800.0f},
                  LoadTexture("Characters/goblin_idle_spritesheet.png"),
                  LoadTexture("Characters/goblin_run_spritesheet.png"));

    Enemy slime2(Vector2{1200.0f, 1200.0f},
                 LoadTexture("Characters/slime_idle_spritesheet.png"),
                 LoadTexture("Characters/slime_run_spritesheet.png"));

    Enemy goblin3(Vector2{1500.0f, 1500.0f},
                  LoadTexture("Characters/goblin_idle_spritesheet.png"),
                  LoadTexture("Characters/goblin_run_spritesheet.png"));

    Enemy slime3(Vector2{2000.0f, 2000.0f},
                 LoadTexture("Characters/slime_idle_spritesheet.png"),
                 LoadTexture("Characters/slime_run_spritesheet.png"));

    Enemy *enemies[]{
        &goblin1,
        &goblin2,
        &goblin3,
        &slime1,
        &slime2,
        &slime3};

    for (auto enemy : enemies)
    {
        enemy->setTarget(&lord);
    }

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

        if (!lord.getAlive())
        { // character is dead
            DrawText("Game Over", windowWidth / 3, windowHeight / 2, 30, RED);
            DrawText("Press q for play again", windowWidth * 2 / 9, windowHeight * 2 / 3, 25, RED);
            if (IsKeyPressed(KEY_Q)) // play again
            {
                lord.playAgain(); // start alive and add 100 to health
            }
        }
        else
        { // character is live
            std::string lordHealth = "Health: ";
            lordHealth.append(std::to_string(lord.getHealth()), 0, 3);
            DrawText(lordHealth.c_str(), windowHeight - 500, 30, 25, WHITE);
        }

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
            if (CheckCollisionRecs(prop.getPropRec(lord.getWorldPos()),
                                   lord.getRec()))
            {
                lord.undoMovement();
            }
        }

        for (auto enemy : enemies)
        {
            enemy->tick(dT);

            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            if (CheckCollisionRecs(enemy->getRec(), lord.getWeaponColRec()))
            {
                enemy->setAlive(false);
            }
        }
        }

        

        EndDrawing();
    }
    CloseWindow();
    UnloadTexture(Map);

    return 0;
}