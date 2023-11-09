#include "raylib/raylib.h"
#include "player.h"
#include "obstacles.h"

bool collision(Player player, Obstacles topObstacles);
void resetObstacle(Player player, Obstacles& topObstacles, Obstacles& bottomObstacles);

const int screenWidth = 1366;
const int screenHeight = 768;

const int minObstacleHeight = 50;
const int maxObstacleHeight = 598;

int main()
{
    Player player;
    player.pos.x = 100;
    player.pos.y = screenHeight / 2;
    player.speed = 400;
    player.width = 60;
    player.height = 60;

    Obstacles topObstacles;
    topObstacles.pos.x = screenWidth;   
    topObstacles.pos.y = 0;
    topObstacles.speed = 600;
    topObstacles.width = 40;
    topObstacles.height = static_cast<int>(GetRandomValue(minObstacleHeight, maxObstacleHeight));
    topObstacles.coolDown = 0;

    Obstacles bottomObstacles;
    bottomObstacles.pos.x = screenWidth;
    bottomObstacles.height = screenHeight - topObstacles.height - bottomObstacles.sepparation;
    bottomObstacles.pos.y = static_cast<float>(screenHeight - bottomObstacles.height);
    bottomObstacles.speed = 600;
    bottomObstacles.width = 40;
    bottomObstacles.coolDown = 0;

    InitWindow(screenWidth, screenHeight, "Flappy Bird");

    while (!WindowShouldClose())    
    {
        playerMovement(player, screenHeight);

        obstaclesMovement(topObstacles, bottomObstacles, screenWidth, screenHeight, minObstacleHeight, maxObstacleHeight);

        resetObstacle(player, topObstacles, bottomObstacles);

        BeginDrawing();

        ClearBackground(BLACK);

        DrawRectangle(static_cast<int>(player.pos.x), static_cast<int>(player.pos.y), player.width, player.height, YELLOW);

        DrawRectangle(static_cast<int>(topObstacles.pos.x), static_cast<int>(topObstacles.pos.y), topObstacles.width, topObstacles.height, GREEN);
        DrawRectangle(static_cast<int>(bottomObstacles.pos.x), static_cast<int>(bottomObstacles.pos.y), bottomObstacles.width, bottomObstacles.height, GREEN);

        DrawText("0.1", 20, 20, 30, WHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

bool collision(Player player, Obstacles obstacles)
{
    if (player.pos.x + player.width >= obstacles.pos.x &&
        player.pos.x <= obstacles.pos.x + obstacles.width &&
        player.pos.y + player.height >= obstacles.pos.y &&
        player.pos.y <= obstacles.pos.y + obstacles.height) {
        return true;
    }
    return false;
}

void resetObstacle(Player player, Obstacles& topObstacles, Obstacles& bottomObstacles)
{
    if (collision(player, topObstacles) || collision(player, bottomObstacles))
    {
        topObstacles.pos.x = screenWidth;
        topObstacles.height = static_cast<int>(GetRandomValue(minObstacleHeight, maxObstacleHeight));
        bottomObstacles.pos.x = screenWidth;
        bottomObstacles.height = static_cast<int>(screenHeight - topObstacles.height - bottomObstacles.sepparation);
        bottomObstacles.pos.y = static_cast<float>(screenHeight - bottomObstacles.height);
    }
}
