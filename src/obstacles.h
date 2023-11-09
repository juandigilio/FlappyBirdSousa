#pragma once
#include "raylib/raylib.h"

struct Obstacles
{
	Vector2 pos;
	int speed;
	int height;
	int width;
	float coolDown;
};

void obstaclesMovement(Obstacles& topObstacle, Obstacles& bottomObstacles, int screenWidth, int screenHeight);