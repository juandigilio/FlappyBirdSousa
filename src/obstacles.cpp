#include "obstacles.h"

#include "gameData.h"

using namespace Globals;

void setObstacles(Obstacles& topObstacles, Obstacles& bottomObstacles)
{
	topObstacles.texture = LoadTexture("assets/gamePlay/urinal.png");
	topObstacles.shitedTexture = LoadTexture("assets/gamePlay/shitedUrinal.png");
	topObstacles.pos.x = static_cast<float>(screenWidth);
	topObstacles.pos.y = 0;
	topObstacles.speed = 600;
	topObstacles.width = topObstacles.texture.width;
	topObstacles.height = static_cast<int>(GetRandomValue(minObstacleHeight, maxObstacleHeight));
	topObstacles.texture.height = topObstacles.height;
	topObstacles.coolDown = 0;

	bottomObstacles.texture = LoadTexture("assets/gamePlay/bottomUrinal.png");
	bottomObstacles.shitedTexture = LoadTexture("assets/gamePlay/bottomShitedUrinal.png");
	bottomObstacles.pos.x = static_cast<float>(screenWidth);
	bottomObstacles.height = screenHeight - topObstacles.height - bottomObstacles.sepparation;
	bottomObstacles.texture.height = bottomObstacles.height;
	bottomObstacles.pos.y = static_cast<float>(screenHeight - bottomObstacles.height);
	bottomObstacles.speed = 600;
	bottomObstacles.width = bottomObstacles.texture.width;
	bottomObstacles.coolDown = 0;
}

void updateObtacles(Obstacles& topObstacles, Obstacles& bottomObstacles)
{
	topObstacles.coolDown += GetFrameTime();

	if (topObstacles.coolDown > 1)
	{		
		topObstacles.pos.x -= topObstacles.speed * GetFrameTime();
		bottomObstacles.pos.x -= bottomObstacles.speed * GetFrameTime();
	}

	if (topObstacles.pos.x < 0 - topObstacles.texture.width)
	{
		topObstacles.pos.x = static_cast<float>(screenWidth);
		topObstacles.coolDown = 0;
		topObstacles.texture.height = static_cast<int>(GetRandomValue(minObstacleHeight, maxObstacleHeight));
		bottomObstacles.pos.x = static_cast<float>(screenWidth);
		bottomObstacles.texture.height = static_cast<int>(screenHeight - topObstacles.texture.height - bottomObstacles.sepparation);
		bottomObstacles.pos.y = static_cast<float>(screenHeight - bottomObstacles.texture.height);
	}
}

void drawObstacles(Obstacles& topObstacles, Obstacles& bottomObstacles)
{
	DrawTexture(topObstacles.texture, static_cast<int>(topObstacles.pos.x), static_cast<int>(topObstacles.pos.y), WHITE);
	DrawTexture(bottomObstacles.texture, static_cast<int>(bottomObstacles.pos.x), static_cast<int>(bottomObstacles.pos.y), WHITE);
}

