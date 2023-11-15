#pragma once
#include "raylib/raylib.h"

struct Player
{
	Vector2 pos;
	int speed;
	int width;
	int height;
	Vector2 velocity = { 0, 0 };
	float gravity = 600.0;
	float jumpForce = -400.0f;
};

void playerMovement(Player& player);