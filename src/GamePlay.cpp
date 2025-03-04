#include "gamePlay.h"

#include "raylib/raylib.h"

#include"gameData.h"
#include "parallax.h"
#include "hud.h"

#include <iostream>

using namespace std;


using namespace Globals;

static void resetStats(Player& player, Player& player2, Obstacles topObstacles[], Obstacles bottomObstacles[])
{
	setPlayer(player, player2);

	setObstacles(topObstacles, bottomObstacles);
}

static void getInput(Player& player, Player& player2)
{
	getPlayerInput(player, player2);
}

static void updateGame(Player& player, Player& player2, Obstacles topObstacles[], Obstacles bottomObstacles[])
{
	bool animationFinished = false;

	if (!player.isColliding && !player2.isColliding)
	{
		updateParallax();

		updatePlayer(player, player2, topObstacles, bottomObstacles);

		updateObtacles(topObstacles, bottomObstacles);
	}
	else
	{
		ShowCrash(player, player2, animationFinished);
	}

	if (animationFinished)
	{
		resetStats(player, player2, topObstacles, bottomObstacles);
		player.isColliding = false;
		player2.isColliding = false;
		animationFinished = false;
	}
}

static void drawGame(Player& player, Player& player2, Obstacles topObstacles[], Obstacles bottomObstacles[])
{
	drawParallax();

	drawPlayer(player);

	if (multiPlayer)
	{
		drawPlayer(player2);
	}

	drawObstacles(topObstacles, bottomObstacles);

	drawHud(player);
}

void gameLoop(Player& player, Player& player2, Obstacles topObstacles[], Obstacles bottomObstacles[])
{
	if (firstTime)
	{
		resetStats(player, player2, topObstacles, bottomObstacles);

		firstTime = false;
	}

	getInput(player, player2);

	updateGame(player, player2, topObstacles, bottomObstacles);

	drawGame(player, player2, topObstacles, bottomObstacles);

	UpdateMusicStream(gameMusic);
}