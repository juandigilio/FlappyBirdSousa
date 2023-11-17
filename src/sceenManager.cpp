#include "sceenManager.h"

#include <iostream>

#include "gameData.h"
#include "player.h"
#include "obstacles.h"

using namespace Globals;

static void loadAssets()
{
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
    idlePlayer = LoadTexture("assets/idleOvni.png");
    jumpingPlayer = LoadTexture("assets/jumpingOvni.png");
}

void runGame()
{
    srand(static_cast<unsigned>(time(NULL)));

    SetConfigFlags(FLAG_MSAA_4X_HINT);

    Player player;
    setPlayer(player);

    Obstacles topObstacles;
    Obstacles bottomObstacles;
    setObstacles(topObstacles, bottomObstacles);

    GameSceen actualScene = GameSceen::Menu;

    GameSceen prevScene = actualScene;

    InitWindow(screenWidth, screenHeight, "Flappy Bird");

    InitAudioDevice();

    loadAssets();

    while (!WindowShouldClose() && !exitProgram)
    {
        newScene = actualScene != prevScene;
        prevScene = actualScene;

        

        switch (actualScene)
        {
        case GameSceen::Menu:
            resetStats(player, topObstacles, bottomObstacles);
            break;
        case GameSceen::Game:
            if (!isGamePaused)
            {
                if (IsMouseButtonPressed(2))
                {
                    actualScene = GameSceen::Pause;
                }
                getPlayerInput(player);
                obstaclesMovement(topObstacles, bottomObstacles, screenWidth, screenHeight, minObstacleHeight, maxObstacleHeight);
                resetObstacle(player, topObstacles, bottomObstacles);
                playerCollitionWhitScreen(player, topObstacles, bottomObstacles);
            }
            parallaxUpdate(scrollingBack, scrollingMid, scrollingFore, backParallax, middleParallax, frontParallax);
            break;
        case GameSceen::Pause:

            break;
        case GameSceen::Credits:

            break;
        case GameSceen::Exit:
            exitProgram = true;
            break;
        default:
            break;
        }

        BeginDrawing();

        ClearBackground(BLACK);

        switch (actualScene)
        {
        case GameSceen::Menu:
            drawMenu(actualScene, screenWidth, playUnselectedButton, playSelectedButton, creditsUnselectedButton, creditsSelectedButton, exitUnselectedButton, exitSelectedButton, backParallax, middleParallax, frontParallax);
            break;
        case GameSceen::Game:
            if (!isGamePaused)
            {
                parallaxDraw(scrollingBack, scrollingMid, scrollingFore, backParallax, middleParallax, frontParallax);
                DrawTexture(player.texture, static_cast<int>(player.pos.x), static_cast<int>(player.pos.y), WHITE);
                DrawRectangle(static_cast<int>(topObstacles.pos.x), static_cast<int>(topObstacles.pos.y), topObstacles.width, topObstacles.height, GREEN);
                DrawRectangle(static_cast<int>(bottomObstacles.pos.x), static_cast<int>(bottomObstacles.pos.y), bottomObstacles.width, bottomObstacles.height, GREEN);
                DrawTexture(pause, screenWidth / 2 - 200, 738, WHITE);
            }
            break;
        case GameSceen::Pause:
            drawPause(actualScene, screenWidth, screenHeight, menuUnselectedButton, menuSelectedButton, resumeUnselectedButton, resumeSelectedButton, backParallax, middleParallax, frontParallax, isGamePaused);
            break;
        case GameSceen::Credits:
            creditsDraw(actualScene, screenWidth, menuUnselectedButton, menuSelectedButton, creditsNachoUnselectedButton, creditsNachoSelectedButton, creditsParallaxUnselectedButton, creditsParallaxSelectedButton, backParallax, middleParallax, frontParallax);
            break;
        case GameSceen::Exit:
            exitProgram = true;
            break;
        default:
            break;
        }

        EndDrawing();
    }

    CloseWindow();
}
