#include "pause.h"

void drawPause(GameScenes& actualScene, int screenWidth, int screenHeight, Texture2D menuUnselectedButton, Texture2D menuSelectedButton, Texture2D resumeUnselectedButton, Texture2D resumeSelectedButton, Texture2D backParallax, Texture2D middleParallax, Texture2D frontParallax, bool& isGamePaused)
{
	staticParallaxDraw(backParallax, middleParallax, frontParallax);

	GameScenes menu = GameScenes::Menu;
	GameScenes resume = GameScenes::Game;

	int middleButtons = screenHeight / 2;

	buttons(actualScene, menu, screenWidth / 2 - 200, middleButtons, 200, 100, menuUnselectedButton, menuSelectedButton);

	if (GetMouseX() >= screenWidth / 2 + 100
		&& GetMouseX() <= screenWidth / 2 + 100 + 100
		&& GetMouseY() >= middleButtons
		&& GetMouseY() <= middleButtons + 50)
	{

		DrawTexture(resumeSelectedButton, screenWidth / 2 + 100, middleButtons, WHITE);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			isGamePaused = false;
			actualScene = resume;
		}
	}
	else
	{
		DrawTexture(resumeUnselectedButton, screenWidth / 2 + 100, middleButtons, WHITE);
	}
}