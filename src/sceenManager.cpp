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
	creditsBackground = LoadTexture("assets/creditsBackground.png");
	backParallax = LoadTexture("assets/backParallax.png");
	middleParallax = LoadTexture("assets/middleParallax.png");
	frontParallax = LoadTexture("assets/frontParallax.png");
	resume = LoadTexture("assets/resume.png");
	menu = LoadTexture("assets/menu.png");
	resumeSelected = LoadTexture("assets/resumeSelected.png");
	menuSelected = LoadTexture("assets/menuSelected.png");
	idlePlayer = LoadTexture("assets/gamePlay/ass.png");
	jumpingPlayer = LoadTexture("assets/gamePlay/assSprite.png");

	jump1 = LoadSound("assets/Sounds/jump1.wav");
	creditsSound = LoadSound("assets/Sounds/credits.wav");
	dead = LoadSound("assets/Sounds/dead.wav");
	menuUnselectedSound = LoadSound("assets/Sounds/menuSelected.wav");
	menuSelectedSound = LoadSound("assets/Sounds/menuUnselected.wav");
	shoot = LoadSound("assets/Sounds/shoot.wav");
	win = LoadSound("assets/Sounds/win.wav");
}

static void unloadAssets(Player& player1, Player& player2, Obstacles topObstacles[], Obstacles bottomObstacles[])
{
	UnloadTexture(menuBackground);
	UnloadTexture(creditsBackground);
	UnloadTexture(backParallax);
	UnloadTexture(middleParallax);
	UnloadTexture(frontParallax);
	UnloadTexture(resume);
	UnloadTexture(menu);
	UnloadTexture(resumeSelected);
	UnloadTexture(menuSelected);
	UnloadTexture(idlePlayer);
	UnloadTexture(jumpingPlayer);

	unloadPlayers(player1, player2);

	unloadObstacles(topObstacles, bottomObstacles);
}

void runGame()
{
	srand(static_cast<unsigned>(time(NULL)));

	SetConfigFlags(FLAG_MSAA_4X_HINT);

	Player player1;
	Player player2;
	Obstacles topObstacles[obstaclesQnty];
	Obstacles bottomObstacles[obstaclesQnty];

	InitWindow(screenWidth, screenHeight, "Farty Butt");

	InitAudioDevice();

	loadAssets();

	setPlayer(player1, player2);

	setObstacles(topObstacles, bottomObstacles);

	while (!exitProgram)
	{
		BeginDrawing();
		ClearBackground(BLACK);

		switch (actualSceen)
		{
			case GameSceen::Menu:
			{
				showMenu();
				break;
			}
			case GameSceen::Game:
			{
				gameLoop(player1, player2, topObstacles, bottomObstacles);
				break;
			}
			case GameSceen::Pause:
			{
				showPause(player1, topObstacles, bottomObstacles);
				break;
			}
			case GameSceen::Credits:
			{
				showCredits();
				break;
			}
			case GameSceen::Exit:
			{
				EndDrawing();
				unloadAssets(player1, player2, topObstacles, bottomObstacles);
				CloseWindow();
				exitProgram = true;
				break;
			}
		}

		if (actualSceen != GameSceen::Exit)
		{
			EndDrawing();
		}
	}
}
