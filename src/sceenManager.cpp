#include "sceenManager.h"

#include <iostream>

#include "gameData.h"
#include "menu.h"
#include "credits.h"
#include "gamePlay.h"
#include "pause.h"
#include "player.h"
#include "obstacles.h"

using namespace Globals;

static void loadAssets()
{
    menuBackground = LoadTexture("assets/menuBackground.png");
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
    idlePlayer = LoadTexture("assets/gamePlay/ass.png");
    jumpingPlayer = LoadTexture("assets/gamePlay/assSprite.png");
}

void runGame()
{
    srand(static_cast<unsigned>(time(NULL)));

    SetConfigFlags(FLAG_MSAA_4X_HINT);

    Player player;
    Player player2;
    Obstacles topObstacles;
    Obstacles bottomObstacles;
   
    GameSceen actualScene = GameSceen::Menu;

    InitWindow(screenWidth, screenHeight, "Flappy Bird");

    InitAudioDevice();    

    loadAssets();

    setPlayer(player, player2);

    setObstacles(topObstacles, bottomObstacles);

    while (!WindowShouldClose() && !exitProgram)
    {
        BeginDrawing();
        ClearBackground(BLACK);

        switch (actualScene)
        {
            case GameSceen::Menu:
            {
                showMenu(actualScene);
                break;
            }          
            case GameSceen::Game:
            {
                gameLoop(player, player2, topObstacles, bottomObstacles);
                break;
            }
            case GameSceen::Pause:
            {

                break;
            }
            case GameSceen::Credits:
            {
                showCredits(actualScene);
                break;
            }
            case GameSceen::Exit:
            {
                CloseWindow();
                break;
            }
        }

        if (actualScene != GameSceen::Exit)
        {
            EndDrawing();
        }
    }
}
