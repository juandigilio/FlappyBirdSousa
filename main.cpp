#include "lib/raylib/raylib.h"
#include "player.h"
#include "obstacles.h"

bool collision(Player player, Obstacles obtacles);
void resetObstacle(Player player, Obstacles& obstacles);

const int screenWidth = 1366;
const int screenHeight = 768;

int main()
{
    Player player;
    player.pos.x = 100;
    player.pos.y = screenHeight / 2;
    player.speed = 400;
    player.width = 60;
    player.height = 60;

    Obstacles obstacles;
    obstacles.pos.x = screenWidth;
    obstacles.height = 150;
    obstacles.pos.y = static_cast<float>(GetRandomValue(0, screenHeight - obstacles.height));
    obstacles.speed = 600;
    obstacles.width = 40;
    obstacles.coolDown = 0;

    InitWindow(screenWidth, screenHeight, "Flappy Bird");

    while (!WindowShouldClose())    
    {
        playerMovement(player, screenHeight);

        obstaclesMovement(obstacles, screenWidth, screenHeight);

        resetObstacle(player, obstacles);

        BeginDrawing();

        ClearBackground(BLACK);

        DrawRectangle(static_cast<int>(player.pos.x), static_cast<int>(player.pos.y), player.width, player.height, YELLOW);

        DrawRectangle(static_cast<int>(obstacles.pos.x), static_cast<int>(obstacles.pos.y), obstacles.width, obstacles.height, GREEN);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

bool collision(Player player, Obstacles obtacles)
{
    if (player.pos.x + player.width >= obtacles.pos.x &&     
        player.pos.x <= obtacles.pos.x + obtacles.width &&       
        player.pos.y + player.height >= obtacles.pos.y &&       
        player.pos.y <= obtacles.pos.y + obtacles.height) {      
        return true;
    }
    return false;
}

void resetObstacle(Player player, Obstacles& obstacles)
{
    if (collision(player, obstacles))
    {
        obstacles.pos.x = screenWidth;
        obstacles.pos.y = static_cast<float>(GetRandomValue(0, screenHeight - obstacles.height));
    }
}