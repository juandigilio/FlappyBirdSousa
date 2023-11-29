#pragma once
#include "raylib/raylib.h"
#include "obstacles.h"

struct Player
{
	Vector2 pos;
	Vector2 velocity;
	int speed;
	float gravity;
	float jumpForce;
	int width;
	int height;
	float rotation;
	int totalPoints;
	Texture2D textureIddle;
	Texture2D textureJumping;
	int frame;
	double lastFrame;
	bool isJumping;
	bool isColliding;
	float lastCollide;

	Rectangle source;

	Vector2 GetCenter()
	{
		return { pos.x + (textureIddle.width / 2), pos.y + (textureIddle.height / 2) };
	}
};

void setPlayer(Player& player, Player& player2);
void getPlayerInput(Player& player, Player& player2);
void updatePlayer(Player& player, Player& player2, Obstacles topObstacles[], Obstacles bottomObstacles[]);
void drawPlayer(Player& player);
void ShowCrash(Player& player);
void unloadPlayers(Player& player1, Player& player2);