#include "obstacles.h"

void obstaclesMovement(Obstacles& obstacles, int screenWidth, int screenHeight)
{
	obstacles.coolDown += GetFrameTime();

	if (obstacles.coolDown > 3)
	{		
		obstacles.pos.x -= obstacles.speed * GetFrameTime();
	}

	if (obstacles.pos.x < 0 - obstacles.width)
	{
		obstacles.pos.x = static_cast<float>(screenWidth);
		obstacles.coolDown = 0;
		obstacles.pos.y = static_cast<float>(GetRandomValue(0, screenHeight - obstacles.height));
	}
}

