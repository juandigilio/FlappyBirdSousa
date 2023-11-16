#include "menu.h"

void drawMenu(GameScenes& actualScene, int screenWidth, Texture2D playUnselectedButton, Texture2D playSelectedButton, Texture2D creditsUnselectedButton, Texture2D creditsSelectedButton, Texture2D exitUnselectedButton, Texture2D exitSelectedButton, Texture2D backParallax, Texture2D middleParallax, Texture2D frontParallax)
{
	Vector2 posMouse = GetMousePosition();

	int height = 100;
	int width = 200;

	int middleButtons = screenWidth / 2 - width / 4;

	staticParallaxDraw(backParallax, middleParallax, frontParallax);

	GameScenes playScene = GameScenes::Game;
	GameScenes creditsScene = GameScenes::Credits;
	GameScenes exitScene = GameScenes::Exit;

	buttons(actualScene, playScene, middleButtons, 300, width, height, playUnselectedButton, playSelectedButton);

	buttons(actualScene, creditsScene, middleButtons, 400, width, height, creditsUnselectedButton, creditsSelectedButton);

	buttons(actualScene, exitScene, middleButtons, 500, width, height, exitUnselectedButton, exitSelectedButton);

	DrawText("0.2", 20, 20, 30, WHITE);
}