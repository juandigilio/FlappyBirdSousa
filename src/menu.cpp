#include "menu.h"

static int height = 100;
static int width = 200;
static int playY = 300;
static int creditsY = 400;
static int exitY = 500;

using namespace Globals;

void drawMenu(GameSceen& actualSceen)
{
	middleButtons = screenWidth / 2 - width / 4;

	staticParallaxDraw(backParallax, middleParallax, frontParallax);

	GameSceen playScene = GameSceen::Game;
	GameSceen creditsScene = GameSceen::Credits;
	GameSceen exitScene = GameSceen::Exit;

	buttons(actualSceen, playScene, middleButtons, 300, width, height, playUnselectedButton, playSelectedButton);

	DrawTexture(playUnselectedButton, middleButtons, 300, WHITE);
	DrawTexture(creditsUnselectedButton, middleButtons, 400, WHITE);
	DrawTexture(exitUnselectedButton, middleButtons, 500, WHITE);

	DrawText("0.2", 20, 20, 30, WHITE);
}

void checkMenuInput()
{
	Vector2 posMouse = GetMousePosition();

	int height = 100;
	int width = 200;

	if (GetMouseX() >= middleButtons
		&& GetMouseX() <= middleButtons + width / 2
		&& GetMouseY() >= playY
		&& GetMouseY() <= playY + height / 2)
	{

		DrawTexture(buttonSelected, middleButtons, buttonY, WHITE);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			actualScene = scene;
		}
	}
	else
	{
		DrawTexture(buttonUnselected, middleButtons, buttonY, WHITE);
	}
}