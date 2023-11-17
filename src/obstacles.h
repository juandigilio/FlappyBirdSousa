#pragma once
#include "raylib/raylib.h"

struct Obstacles
{
	Vector2 pos = { 0, 0 };
	int speed = 0;
	int height = 0;
	int width = 0;
	float coolDown = 0;
	int sepparation = 120;
};

void setObstacles(Obstacles& topObstacles, Obstacles& bottomObstacles);
void obstaclesMovement(Obstacles& topObstacle, Obstacles& bottomObstacles, int screenWidth, int screenHeight, int minObstacleHeight, int maxObstacleHeight);