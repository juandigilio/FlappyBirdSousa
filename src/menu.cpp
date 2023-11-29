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
	
	Vector2 position{ 20, screenHeight - fontSize * 0.5f };
	float spacing = 1.0f;

	DrawTextEx(font, "Version 0.9", position, fontSize * 0.4f, spacing, BLACK);
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

		if (!isClicking)
		{
			isClicking = true;

			PlaySound(menuUnselectedSound);
		}

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			PlaySound(menuSelectedSound);
			actualSceen = GameSceen::Game;
			PlayMusicStream(gameMusic);
		}
	}
	else if (CheckCollisionPointRec(GetMousePosition(), multiPlayeRec))
	{
		menuSource.x = static_cast<float>(menuBackgroundWidth) * 2.0f;

		if (!isClicking)
		{
			isClicking = true;

			PlaySound(menuUnselectedSound);
		}

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			PlaySound(menuSelectedSound);
			multiPlayer = true;
			actualSceen = GameSceen::Game;
			PlayMusicStream(gameMusic);
		}
	}
	else if (CheckCollisionPointRec(GetMousePosition(), credits))
	{
		menuSource.x = static_cast<float>(menuBackgroundWidth) * 3.0f;

		if (!isClicking)
		{
			isClicking = true;

			PlaySound(menuUnselectedSound);
		}

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			PlaySound(menuSelectedSound);
			actualSceen = GameSceen::Credits;
			PlayMusicStream(creditsMusic);
		}
	}
	else if (CheckCollisionPointRec(GetMousePosition(), exit))
	{
		menuSource.x = static_cast<float>(menuBackgroundWidth) * 4.0f;

		if (!isClicking)
		{
			isClicking = true;

			PlaySound(menuUnselectedSound);
		}

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			PlaySound(menuSelectedSound);
			actualSceen = GameSceen::Exit;
		}
	}
	else
	{
		isClicking = false;
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