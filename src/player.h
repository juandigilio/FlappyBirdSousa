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
};

void playerMovement(Player& player);
Texture2D changeTexture(Texture2D jumpingPlayer, Texture2D idlePlayer, Player player);