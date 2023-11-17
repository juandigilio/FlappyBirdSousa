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
	Texture2D textureIddle;
	Texture2D textureJumping;
	int frame;
	double lastFrame;
	bool isJumping;
	bool isColliding;

	Rectangle source;

	Vector2 GetCenter()
	{
		return { pos.x + (textureIddle.width / 2), pos.y + (textureIddle.height / 2) };
	}
};

void setPlayer(Player& player);
void getPlayerInput(Player& player);
void updatePlayer(Player& player, Obstacles& topObstacles, Obstacles& bottomObstacles);
void drawPlayer(Player& player);