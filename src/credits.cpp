#include "credits.h"

#include <iostream>


using namespace std;
using namespace Globals;

static int xCredits = screenWidth / 2 - 200;
static int yCredits = 400;
static int parallaxCreditsY = 300;

static void drawCredits()
{
	DrawTexturePro(creditsBackground, menuSource, menuDest, { 0, 0 }, 0.0f, RAYWHITE);
}

static void getCreditsInput()
{
	Vector2 sousa1 = { 350, 452 };
	Vector2 sousa2 = { 281, 555 };
	Vector2 sousa3 = { 422, 557 };

	Vector2 digilio1 = { 950, 455 };
	Vector2 digilio2 = { 890, 556 };
	Vector2 digilio3 = { 1030, 554 };



	if (CheckCollisionPointTriangle(GetMousePosition(), digilio1, digilio2, digilio3))
	{
		menuSource.x = static_cast<float>(menuBackgroundWidth);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			OpenURL("https://github.com/juandigilio");
			OpenURL("https://juandigilio.itch.io/");
		}
	}
	else if (CheckCollisionPointTriangle(GetMousePosition(), sousa1, sousa2, sousa3))
	{
		menuSource.x = static_cast<float>(menuBackgroundWidth) * 2.0f;

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			OpenURL("https://github.com/nachosou");
			OpenURL("https://nachosou.itch.io/");
		}
	}
	else
	{
		menuSource.x = 0;
	}

	if (IsKeyPressed(KEY_ESCAPE))
	{
		actualSceen = GameSceen::Menu;
	}

	cout << "X: " << GetMouseX() << endl;
	cout << "Y: " << GetMouseY() << endl;
}

void showCredits()
{
	drawCredits();

	getCreditsInput();
}