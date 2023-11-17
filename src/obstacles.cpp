#include "obstacles.h"

#include "gameData.h"

using namespace Globals;

void setObstacles(Obstacles& topObstacles, Obstacles& bottomObstacles)
{
	topObstacles.pos.x = screenWidth;
	topObstacles.pos.y = 0;
	topObstacles.speed = 600;
	topObstacles.width = 40;
	topObstacles.height = static_cast<int>(GetRandomValue(minObstacleHeight, maxObstacleHeight));
	topObstacles.coolDown = 0;

	bottomObstacles.pos.x = screenWidth;
	bottomObstacles.height = screenHeight - topObstacles.height - bottomObstacles.sepparation;
	bottomObstacles.pos.y = static_cast<float>(screenHeight - bottomObstacles.height);
	bottomObstacles.speed = 600;
	bottomObstacles.width = 40;
	bottomObstacles.coolDown = 0;
}

void obstaclesMovement(Obstacles& topObstacles, Obstacles& bottomObstacles, int screenWidth, int screenHeight, int minObstacleHeight, int maxObstacleHeight)
{
	topObstacles.coolDown += GetFrameTime();

	if (topObstacles.coolDown > 1)
	{		
		topObstacles.pos.x -= topObstacles.speed * GetFrameTime();
		bottomObstacles.pos.x -= bottomObstacles.speed * GetFrameTime();
	}

	if (topObstacles.pos.x < 0 - topObstacles.width)
	{
		topObstacles.pos.x = static_cast<float>(screenWidth);
		topObstacles.coolDown = 0;
		topObstacles.height = static_cast<int>(GetRandomValue(minObstacleHeight, maxObstacleHeight));
		bottomObstacles.pos.x = static_cast<float>(screenWidth);
		bottomObstacles.height = static_cast<int>(screenHeight - topObstacles.height - bottomObstacles.sepparation);
		bottomObstacles.pos.y = static_cast<float>(screenHeight - bottomObstacles.height);
	}
}

