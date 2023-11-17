#include "menu.h"

static int height = 100;
static int width = 200;
static int playY = 300;
static int creditsY = 400;
static int exitY = 500;

using namespace Globals;

static void drawMenu()
{
	middleButtons = screenWidth / 2 - width / 4;

	staticParallaxDraw();

	DrawTexture(playUnselectedButton, middleButtons, 300, WHITE);
	DrawTexture(creditsUnselectedButton, middleButtons, 400, WHITE);
	DrawTexture(exitUnselectedButton, middleButtons, 500, WHITE);

	DrawText("Version: 0.2", 20, 20, 30, WHITE);
}

static void checkMenuInput(GameSceen& actualSceen)
{
	Vector2 posMouse = GetMousePosition();

	if (GetMouseX() >= middleButtons
		&& GetMouseX() <= middleButtons + width / 2
		&& GetMouseY() >= playY
		&& GetMouseY() <= playY + height / 2)
	{
		DrawTexture(playSelectedButton, middleButtons, playY, WHITE);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			actualSceen = GameSceen::Game;
		}
	}
	
	if (GetMouseX() >= middleButtons
		&& GetMouseX() <= middleButtons + width / 2
		&& GetMouseY() >= creditsY
		&& GetMouseY() <= creditsY + height / 2)
	{
		DrawTexture(creditsSelectedButton, middleButtons, creditsY, WHITE);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			actualSceen = GameSceen::Credits;
		}
	}

	if (GetMouseX() >= middleButtons
		&& GetMouseX() <= middleButtons + width / 2
		&& GetMouseY() >= exitY
		&& GetMouseY() <= exitY + height / 2)
	{
		DrawTexture(exitSelectedButton, middleButtons, exitY, WHITE);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			actualSceen = GameSceen::Exit;
		}
	}
}

void showMenu(GameSceen& actualSceen)
{
	if (!firstTime)
	{
		firstTime = true;
	}

	drawMenu();

	checkMenuInput(actualSceen);
}