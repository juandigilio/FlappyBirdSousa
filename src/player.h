#pragma once
#include "raylib/raylib.h"
#include "obstacles.h"

struct Player
{
	Vector2 pos;
	int speed;
	int width;
	int height;
	Vector2 velocity;
	float gravity;
	float jumpForce;
};

void playerMovement(Player& player);