#include "obstacles.h"

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

