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
	menuBackground = LoadTexture("Assets/menuBackground.png");
	creditsBackground = LoadTexture("Assets/creditsBackground.png");
	backParallax = LoadTexture("Assets/backParallax.png");
	middleParallax = LoadTexture("Assets/middleParallax.png");
	frontParallax = LoadTexture("Assets/frontParallax.png");
	resume = LoadTexture("Assets/resume.png");
	menu = LoadTexture("Assets/menu.png");
	resumeSelected = LoadTexture("Assets/resumeSelected.png");
	menuSelected = LoadTexture("Assets/menuSelected.png");

	jump1 = LoadSound("Assets/Sounds/jump1.wav");
	creditsSound = LoadSound("Assets/Sounds/credits.wav");
	dead = LoadSound("Assets/Sounds/dead.wav");
	menuUnselectedSound = LoadSound("Assets/Sounds/menuSelected.wav");
	menuSelectedSound = LoadSound("Assets/Sounds/menuUnselected.wav");
	shoot = LoadSound("Assets/Sounds/shoot.wav");
	win = LoadSound("Assets/Sounds/win.wav");

	font = LoadFont("Assets/Fonts/dpcomic.ttf");
	fontSize = font.baseSize * 2.0f;
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
