#include "pause.h"

#include "parallax.h"

using namespace Globals;

static void drawPause()
{
	staticParallaxDraw();

	DrawTexture(resumeUnselectedButton, screenWidth / 2 + 100, middleButtons, WHITE);
}

static void getPausedInput(GameSceen& actualSceen)
{
	if (GetMouseX() >= screenWidth / 2 + 100
		&& GetMouseX() <= screenWidth / 2 + 100 + 100
		&& GetMouseY() >= middleButtons
		&& GetMouseY() <= middleButtons + 50)
	{
		DrawTexture(resumeSelectedButton, screenWidth / 2 + 100, middleButtons, WHITE);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			actualSceen = GameSceen::Game;
		}
	}
}

void showPause(GameSceen& actualScene)
{
	drawPause();

	getPausedInput(actualScene);
}