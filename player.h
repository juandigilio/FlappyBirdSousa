#pragma once
#include "lib/raylib/raylib.h"

struct Player
{
	Vector2 pos;
	int speed;
	int width;
	int height;
};

void playerMovement(Player& player, int screenHeight);