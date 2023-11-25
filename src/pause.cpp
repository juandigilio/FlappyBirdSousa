#include "pause.h"

#include "parallax.h"


using namespace Globals;

static void drawPause(Player player, Obstacles topObstacles[], Obstacles bottomObstacles[])
{
	staticParallaxDraw();

	drawPlayer(player);
	drawObstacles(topObstacles, bottomObstacles);
	DrawTexture(resume, static_cast<int>(resumePos.x), static_cast<int>(resumePos.y), WHITE);
	DrawTexture(menu, static_cast<int>(menuPos.x), static_cast<int>(menuPos.y), WHITE);

}

static void getPausedInput()
{
	if (CheckCollisionPointRec(GetMousePosition(), menuPos))
	{
		DrawTexture(menuSelected, static_cast<int>(menuPos.x), static_cast<int>(menuPos.y), WHITE);
		
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			actualSceen = GameSceen::Menu;
		}
	}
	else if (CheckCollisionPointRec(GetMousePosition(), resumePos))
	{
		DrawTexture(resumeSelected, static_cast<int>(resumePos.x), static_cast<int>(resumePos.y), WHITE);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			actualSceen = GameSceen::Game;
		}
	}

	if (IsKeyPressed(KEY_ESCAPE))
	{
		actualSceen = GameSceen::Game;
	}
}

void showPause(Player player, Obstacles topObstacles[], Obstacles bottomObstacles[])
{
	drawPause(player, topObstacles, bottomObstacles);

	getPausedInput();
}