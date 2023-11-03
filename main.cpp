#include "lib/raylib/raylib.h"
#include "player.h"

int main()
{
    const int screenWidth = 1366;
    const int screenHeight = 768;

    Player player;
    player.pos.x = 100;
    player.pos.y = screenHeight / 2;
    player.speed = 400;
    player.width = 60;
    player.height = 60;

    InitWindow(screenWidth, screenHeight, "Flappy Bird");

    while (!WindowShouldClose())    
    {
        playerMovement(player, screenHeight);

        BeginDrawing();

        ClearBackground(BLACK);

        DrawRectangle(static_cast<int>(player.pos.x), static_cast<int>(player.pos.y), player.width, player.height, YELLOW);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}