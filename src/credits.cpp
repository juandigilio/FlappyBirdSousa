#include "credits.h"

void creditsDraw(GameScenes& actualScene, int screenWidth, Texture2D menuUnselectedButton, Texture2D menuSelectedButton, Texture2D creditsNachoUnselectedButton, Texture2D creditsNachoSelectedButton, Texture2D creditsParallaxUnselectedButton, Texture2D creditsParallaxSelectedButton,Texture2D backParallax, Texture2D middleParallax, Texture2D frontParallax)
{
	int height = 100;
	int width = 200;

	int middleButtons = screenWidth / 2 - width / 4;
	int xCredits = screenWidth / 2 - 200;
	int yCredits = 400;
	int parallaxCreditsY = 300;

	GameScenes menuScene = GameScenes::Menu;

	staticParallaxDraw(backParallax, middleParallax, frontParallax);

	if (GetMouseX() >= xCredits
		&& GetMouseX() <= xCredits + 394
		&& GetMouseY() >= yCredits
		&& GetMouseY() <= yCredits + 28)
	{

		DrawTexture(creditsNachoSelectedButton, xCredits, yCredits, WHITE);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			OpenURL("https://nachosou.itch.io");
		}
	}
	else
	{
		DrawTexture(creditsNachoUnselectedButton, xCredits, yCredits, WHITE);
	}

	if (GetMouseX() >= middleButtons
		&& GetMouseX() <= middleButtons + width / 2
		&& GetMouseY() >= parallaxCreditsY
		&& GetMouseY() <= parallaxCreditsY + height / 2)
	{

		DrawTexture(creditsParallaxSelectedButton, middleButtons, parallaxCreditsY, WHITE);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			OpenURL("https://es.vecteezy.com/vectores-gratis/parallax");
		}
	}
	else
	{
		DrawTexture(creditsParallaxUnselectedButton, middleButtons, parallaxCreditsY, WHITE);
	}

	buttons(actualScene, menuScene, 899, 618, 200, 100, menuUnselectedButton, menuSelectedButton);
}