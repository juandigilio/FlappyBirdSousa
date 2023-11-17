#include "gamePlay.h"

#include "raylib/raylib.h"

#include"gameData.h"
#include "parallax.h"

using namespace Globals;

static void resetStats(Player& player, Obstacles& topObstacles, Obstacles& bottomObstacles)
{
	setPlayer(player);
	setObstacles(topObstacles, bottomObstacles);
}

static void updateGame(Player& player, Obstacles& topObstacles, Obstacles& bottomObstacles)
{
	updateParallax();

	updatePlayer(player, topObstacles, bottomObstacles);

	updateObtacles(topObstacles, bottomObstacles);

	if (player.isColliding)
	{
		resetStats(player, topObstacles, bottomObstacles);
		player.isColliding = false;
	}
}

static void drawGame(Player player, Obstacles topObstacles, Obstacles bottomObstacles)
{
	drawParallax();

	drawPlayer(player);

	drawObstacles(topObstacles, bottomObstacles);
}

void gameLoop(Player& player, Obstacles& topObstacles, Obstacles& bottomObstacles)
{
	if (firstTime)
	{
		resetStats(player, topObstacles, bottomObstacles);

		firstTime = false;
	}

	getPlayerInput(player);

	updateGame(player, topObstacles, bottomObstacles);

	drawGame(player, topObstacles, bottomObstacles);
}