#include "credits.h"

using namespace Globals;

static int xCredits = screenWidth / 2 - 200;
static int yCredits = 400;
static int parallaxCreditsY = 300;

static void drawCredits()
{	
	staticParallaxDraw();

	DrawTexture(creditsNachoUnselectedButton, xCredits, yCredits, WHITE);

	DrawTexture(creditsParallaxUnselectedButton, middleButtons, parallaxCreditsY, WHITE);
}

static void getCreditsInput(GameSceen& actualSceen)
{
	int height = 100;
	int width = 200;

	if (GetMouseX() >= xCredits
		&& GetMouseX() <= xCredits + 394
		&& GetMouseY() >= yCredits
		&& GetMouseY() <= yCredits + 28)
	{
		DrawTexture(creditsNachoSelectedButton, xCredits, yCredits, WHITE);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			OpenURL("https://juandigilio.itch.io/");
		}
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

	if (IsKeyPressed(KEY_ESCAPE))
	{
		actualSceen = GameSceen::Menu;
	}
}

void showCredits(GameSceen& actualSceen)
{
	drawCredits();

	getCreditsInput(actualSceen);
}