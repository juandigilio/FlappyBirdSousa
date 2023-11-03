#pragma once
#include "lib/raylib/raylib.h"

struct Obstacles
{
	Vector2 pos;
	int speed;
	int height;
	int width;
	float coolDown;
};

void obstaclesMovement(Obstacles& obstacles, int screenWidth, int screenHeight);