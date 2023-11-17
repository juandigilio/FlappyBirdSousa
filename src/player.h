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
	Texture2D texture;
	bool isJumping;
	bool isColliding;
};

void setPlayer(Player& player);
void getPlayerInput(Player& player);
void updatePlayer(Player& player, Obstacles& topObstacles, Obstacles& bottomObstacles);
void drawPlayer(Player& player);