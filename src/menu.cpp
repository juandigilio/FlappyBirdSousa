#include "menu.h"

#include <iostream>



static int height = 100;
static int width = 200;
static int playY = 300;
static int multiY = 400;
static int creditsY = 500;
static int exitY = 600;

using namespace std;
using namespace Globals;

static void drawMenu()
{
	middleButtons = screenWidth / 2 - width / 4;

	DrawTexturePro(menuBackground, menuSource, menuDest, { 0, 0 }, 0.0f, RAYWHITE);

	DrawText("Version: 0.3", 20, 20, 30, WHITE);
}

static void checkMenuInput()
{
	Rectangle sinlgePlayer =  {163.0f, 200.0f, 54.0f, 268.0f};
	Rectangle multiPlayeRec =  {452.0f, 215.0f, 54.0f, 268.0f};
	Rectangle credits =  {934.0f, 215.0f, 54.0f, 268.0f};
	Rectangle exit =  {1193.0f, 212.0f, 54.0f, 268.0f};


	if (CheckCollisionPointRec(GetMousePosition(), sinlgePlayer))
	{
		menuSource.x = static_cast<float>(menuBackgroundWidth);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			actualSceen = GameSceen::Game;
		}
	}
	else if (CheckCollisionPointRec(GetMousePosition(), multiPlayeRec))
	{
		menuSource.x = static_cast<float>(menuBackgroundWidth) * 2.0f;

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			multiPlayer = true;
			actualSceen = GameSceen::Game;
		}
	}
	else if (CheckCollisionPointRec(GetMousePosition(), credits))
	{
		menuSource.x = static_cast<float>(menuBackgroundWidth) * 3.0f;

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			actualSceen = GameSceen::Credits;
		}
	}
	else if (CheckCollisionPointRec(GetMousePosition(), exit))
	{
		menuSource.x = static_cast<float>(menuBackgroundWidth) * 4.0f;

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			actualSceen = GameSceen::Exit;
		}
	}
	else
	{
		menuSource.x = 0.0f;
	}
}

void showMenu()
{
	if (!firstTime)
	{
		firstTime = true;
	}

	drawMenu();

	checkMenuInput();
}