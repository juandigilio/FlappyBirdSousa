#pragma once
#include "raylib/raylib.h"

const int obstaclesQnty = 2;

struct Obstacles
{
	Texture2D texture;
	Texture2D shitedTexture;
	Vector2 pos = { 0, 0 };
	int speed = 0;
	int height = 0;
	int width = 0;
	float coolDown = 0;
	int sepparation = 200;
};

void setObstacles(Obstacles topObstacles[], Obstacles bottomObstacles[]);
void updateObtacles(Obstacles topObstacle[], Obstacles bottomObstacles[]);
void drawObstacles(Obstacles topObstacles[], Obstacles bottomObstacles[]);