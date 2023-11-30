#include "obstacles.h"

#include "gameData.h"

using namespace Globals;


void setObstacles(Obstacles topObstacles[], Obstacles bottomObstacles[])
{
	for (int i = 0; i < obstaclesQnty; i++)
	{
		if (firstTime)
		{
			topObstacles[i].texture = LoadTexture("Assets/GamePlay/urinal.png");
			topObstacles[i].shitedTexture = LoadTexture("Assets/GamePlay/shitedUrinal.png");
			bottomObstacles[i].texture = LoadTexture("Assets/GamePlay/bottomUrinal.png");
			bottomObstacles[i].shitedTexture = LoadTexture("Assets/GamePlay/bottomShitedUrinal.png");
		}

		topObstacles[i].pos.x = static_cast<float>(screenWidth + (i * 683));
		topObstacles[i].pos.y = 0;
		topObstacles[i].speed = 600;
		topObstacles[i].width = topObstacles[i].texture.width;
		topObstacles[i].height = static_cast<int>(GetRandomValue(minObstacleHeight, maxObstacleHeight));
		topObstacles[i].texture.height = topObstacles[i].height;
		topObstacles[i].shitedTexture.height = topObstacles[i].height;
		topObstacles[i].coolDown = 0;
		topObstacles[i].isShited = false;

		bottomObstacles[i].pos.x = static_cast<float>(screenWidth + (i * 683));
		bottomObstacles[i].height = screenHeight - topObstacles[i].height - bottomObstacles[i].sepparation;
		bottomObstacles[i].texture.height = bottomObstacles[i].height;
		bottomObstacles[i].shitedTexture.height = bottomObstacles[i].height;
		bottomObstacles[i].pos.y = static_cast<float>(screenHeight - bottomObstacles[i].height);
		bottomObstacles[i].speed = 600;
		bottomObstacles[i].width = bottomObstacles[i].texture.width;
		bottomObstacles[i].coolDown = 0;
		bottomObstacles[i].isShited = false;
	}
}

void updateObtacles(Obstacles topObstacles[], Obstacles bottomObstacles[])
{
	for (int i = 0; i < obstaclesQnty; i++)
	{
		topObstacles[i].coolDown += GetFrameTime();

		if (topObstacles[i].coolDown > 1)
		{
			topObstacles[i].pos.x -= topObstacles[i].speed * GetFrameTime();
			bottomObstacles[i].pos.x -= bottomObstacles[i].speed * GetFrameTime();
		}

		if (topObstacles[i].pos.x < 0 - topObstacles[i].texture.width)
		{
			topObstacles[i].pos.x = static_cast<float>(screenWidth);
			topObstacles[i].coolDown = 0;
			topObstacles[i].texture.height = static_cast<int>(GetRandomValue(minObstacleHeight, maxObstacleHeight));
			topObstacles[i].shitedTexture.height = topObstacles[i].texture.height;
			bottomObstacles[i].pos.x = static_cast<float>(screenWidth);
			bottomObstacles[i].texture.height = static_cast<int>(screenHeight - topObstacles[i].texture.height - bottomObstacles[i].sepparation);
			bottomObstacles[i].shitedTexture.height = bottomObstacles[i].texture.height;
			bottomObstacles[i].pos.y = static_cast<float>(screenHeight - bottomObstacles[i].texture.height);
		}
	}
}

void drawObstacles(Obstacles topObstacles[], Obstacles bottomObstacles[])
{
	for (int i = 0; i < obstaclesQnty; i++)
	{
		if (topObstacles[i].isShited)
		{
			DrawTexture(topObstacles[i].shitedTexture, static_cast<int>(topObstacles[i].pos.x), static_cast<int>(topObstacles[i].pos.y), WHITE);
		}
		else
		{
			DrawTexture(topObstacles[i].texture, static_cast<int>(topObstacles[i].pos.x), static_cast<int>(topObstacles[i].pos.y), WHITE);
		}
		
		if (bottomObstacles[i].isShited)
		{
			DrawTexture(bottomObstacles[i].shitedTexture, static_cast<int>(bottomObstacles[i].pos.x), static_cast<int>(bottomObstacles[i].pos.y), WHITE);
		}
		else
		{
			DrawTexture(bottomObstacles[i].texture, static_cast<int>(bottomObstacles[i].pos.x), static_cast<int>(bottomObstacles[i].pos.y), WHITE);
		}
	}
}

void unloadObstacles(Obstacles topObstacles[], Obstacles bottomObstacles[])
{
	for (int i = 0; i < obstaclesQnty; i++)
	{
		UnloadTexture(topObstacles[i].texture);
		UnloadTexture(topObstacles[i].shitedTexture);
		UnloadTexture(bottomObstacles[i].texture);
		UnloadTexture(bottomObstacles[i].shitedTexture);
	}
}

