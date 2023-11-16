#include "raylib/raylib.h"
#include "raylib/raymath.h"
#include "player.h"
#include "obstacles.h"
#include "parallax.h"
#include "scenes.h"
#include "credits.h"
#include "menu.h"
#include "pause.h"

bool collision(Player player, Obstacles topObstacles);
void resetObstacle(Player player, Obstacles& topObstacles, Obstacles& bottomObstacles);
void playerCollitionWhitScreen(Player& player, Obstacles& topObstacles, Obstacles& bottomObstacles);
void resetStats(Player& player, Obstacles& topObstacles, Obstacles& bottomObstacles);

const int screenWidth = 1366;
const int screenHeight = 768;

const int minObstacleHeight = 100;
const int maxObstacleHeight = 500;

Texture2D backParallax;
Texture2D middleParallax;
Texture2D frontParallax;
Texture2D menuUnselectedButton;
Texture2D menuSelectedButton;
Texture2D playUnselectedButton;
Texture2D playSelectedButton;
Texture2D creditsUnselectedButton;
Texture2D creditsSelectedButton;
Texture2D exitUnselectedButton;
Texture2D exitSelectedButton;
Texture2D creditsParallaxUnselectedButton;
Texture2D creditsParallaxSelectedButton;
Texture2D creditsNachoUnselectedButton;
Texture2D creditsNachoSelectedButton;
Texture2D resumeUnselectedButton;
Texture2D resumeSelectedButton;
Texture2D pause;

int main()
{
    Player player;
    player.pos.x = 100;
    player.pos.y = screenHeight / 2;
    player.speed = 400;
    player.width = 60;
    player.height = 60;
    player.velocity = { 0, 0 };
    player.gravity = 600.0;
    player.jumpForce = -400.0f;

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

    GameScenes actualScene = GameScenes::Menu;
    bool newScene = true;
    GameScenes prevScene = actualScene;

    bool exitProgram = false;
    bool isGamePaused = false;

    float scrollingBack = 0.0f;
    float scrollingMid = 0.0f;
    float scrollingFore = 0.0f;

    InitWindow(screenWidth, screenHeight, "Flappy Bird");

    backParallax = LoadTexture("assets/backParallax.png");
    middleParallax = LoadTexture("assets/middleParallax.png");
    frontParallax = LoadTexture("assets/frontParallax.png");
    menuUnselectedButton = LoadTexture("assets/menuUnselectedButton.png");
    menuSelectedButton = LoadTexture("assets/menuSelectedButton.png");
    playUnselectedButton = LoadTexture("assets/playUnselectedButton.png");
    playSelectedButton = LoadTexture("assets/playSelectedButton.png");
    creditsUnselectedButton = LoadTexture("assets/creditsUnselectedButton.png");
    creditsSelectedButton = LoadTexture("assets/creditsSelectedButton.png");
    exitUnselectedButton = LoadTexture("assets/exitUnselectedButton.png");
    exitSelectedButton = LoadTexture("assets/exitSelectedButton.png");
    creditsParallaxUnselectedButton = LoadTexture("assets/parallaxUnselectedButton.png");
    creditsParallaxSelectedButton = LoadTexture("assets/parallaxSelectedButton.png");
    creditsNachoUnselectedButton = LoadTexture("assets/creditsUnselectedNacho.png");
    creditsNachoSelectedButton = LoadTexture("assets/creditsSelectedNacho.png");
    resumeUnselectedButton = LoadTexture("assets/resumeUnselectedButton.png");
    resumeSelectedButton = LoadTexture("assets/resumeSelectedButton.png");
    pause = LoadTexture("assets/pause.png");

    while (!WindowShouldClose() && !exitProgram)
    {
        newScene = actualScene != prevScene;
        prevScene = actualScene;

        switch (actualScene)
        {
        case GameScenes::Menu:
            resetStats(player, topObstacles, bottomObstacles);
            break;
        case GameScenes::Game:
            if (!isGamePaused) 
            {  
                if (IsMouseButtonPressed(2))
                {
                    actualScene = GameScenes::Pause;
                }
                playerMovement(player);
                obstaclesMovement(topObstacles, bottomObstacles, screenWidth, screenHeight, minObstacleHeight, maxObstacleHeight);
                resetObstacle(player, topObstacles, bottomObstacles);
                playerCollitionWhitScreen(player, topObstacles, bottomObstacles);
            }
            parallaxUpdate(scrollingBack, scrollingMid, scrollingFore, backParallax, middleParallax, frontParallax);
            break;
        case GameScenes::Pause:

            break;
        case GameScenes::Credits:
            
            break;
        case GameScenes::Exit:
            exitProgram = true;
            break;
        default:
            break;
        }

        BeginDrawing();

        ClearBackground(BLACK);

        switch (actualScene)
        {
        case GameScenes::Menu:
            drawMenu(actualScene, screenWidth, playUnselectedButton, playSelectedButton, creditsUnselectedButton, creditsSelectedButton, exitUnselectedButton, exitSelectedButton, backParallax, middleParallax, frontParallax);
            break;
        case GameScenes::Game:
            if (!isGamePaused)
            {
                parallaxDraw(scrollingBack, scrollingMid, scrollingFore, backParallax, middleParallax, frontParallax);
                DrawRectangle(static_cast<int>(player.pos.x), static_cast<int>(player.pos.y), player.width, player.height, BLACK);
                DrawRectangle(static_cast<int>(topObstacles.pos.x), static_cast<int>(topObstacles.pos.y), topObstacles.width, topObstacles.height, GREEN);
                DrawRectangle(static_cast<int>(bottomObstacles.pos.x), static_cast<int>(bottomObstacles.pos.y), bottomObstacles.width, bottomObstacles.height, GREEN);
                DrawTexture(pause, screenWidth / 2 - 200, 738, WHITE);
            }
            break;
        case GameScenes::Pause:
            drawPause(actualScene, screenWidth, screenHeight, menuUnselectedButton, menuSelectedButton, resumeUnselectedButton, resumeSelectedButton, backParallax, middleParallax, frontParallax, isGamePaused);
            break;
        case GameScenes::Credits:
            creditsDraw(actualScene, screenWidth, menuUnselectedButton, menuSelectedButton, creditsNachoUnselectedButton, creditsNachoSelectedButton, creditsParallaxUnselectedButton, creditsParallaxSelectedButton, backParallax, middleParallax, frontParallax);
            break;
        case GameScenes::Exit:
            exitProgram = true;
            break;
        default:
            break;
        }
     
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
        topObstacles.coolDown = 0;
        bottomObstacles.height = static_cast<int>(screenHeight - topObstacles.height - bottomObstacles.sepparation);
        bottomObstacles.pos.y = static_cast<float>(screenHeight - bottomObstacles.height);
    }
}

void playerCollitionWhitScreen(Player& player, Obstacles& topObstacles, Obstacles& bottomObstacles)
{
    if (player.pos.y <= 0)
    {
        player.jumpForce = 0.0f;
        player.pos.y = 0;
    }
    else
    {
        player.jumpForce = -400.0f;
    }

    if (player.pos.y >= screenHeight - player.height)
    {
        resetStats(player, topObstacles, bottomObstacles);
    }
}

void resetStats(Player& player, Obstacles& topObstacles, Obstacles& bottomObstacles)
{
    player.pos.x = 100;
    player.pos.y = static_cast<float>(screenHeight / 2);
    player.speed = 400;
    player.width = 60;
    player.height = 60;
    player.velocity = { 0, 0 };
    player.gravity = 600.0;
    player.jumpForce = -400.0f;

    topObstacles.pos.x = static_cast<float>(screenWidth);
    topObstacles.pos.y = 0;
    topObstacles.speed = 600;
    topObstacles.width = 40;
    topObstacles.height = static_cast<int>(GetRandomValue(minObstacleHeight, maxObstacleHeight));
    topObstacles.coolDown = 0;

    bottomObstacles.pos.x = static_cast<float>(screenWidth);
    bottomObstacles.height = screenHeight - topObstacles.height - bottomObstacles.sepparation;
    bottomObstacles.pos.y = static_cast<float>(screenHeight - bottomObstacles.height);
    bottomObstacles.speed = 600;
    bottomObstacles.width = 40;
    bottomObstacles.coolDown = 0;
}