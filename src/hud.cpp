#include "hud.h"

#include "raylib/raylib.h"

#include "gameData.h"

using namespace Globals;

void drawHud(Player& player)
{
	Vector2 position{ 20, screenHeight - fontSize };
	float spacing = 1.0f;

	Color color;

	if (player.totalPoints >= highScore)
	{
		color = GREEN;
	}
	else
	{
		color = RED;
	}

	DrawTextEx(font, "Distance: ", position, fontSize * 0.4f, spacing, color);

	position.x += MeasureTextEx(font, "Distance: ", fontSize * 0.4f, spacing).x;
	DrawTextEx(font, TextFormat("%01i", player.totalPoints), position, fontSize * 0.4f, spacing, color);

	position.x += MeasureTextEx(font, TextFormat("%01i", player.totalPoints), fontSize * 0.4f, spacing).x;
	DrawTextEx(font, "M", position, fontSize * 0.4f, spacing, color);

	float distance = (MeasureTextEx(font, "High Score: ", fontSize * 0.4f, spacing).x) + (MeasureTextEx(font, TextFormat("%01i", highScore), fontSize * 0.4f, spacing).x);
	
	position.x = screenWidth - distance - 40.0f;

	if (player.totalPoints >= highScore)
	{
		color = RED;
	}
	else
	{
		color = GREEN;
	}

	DrawTextEx(font, "High Score: ", position, fontSize * 0.4f, spacing, color);

	position.x += MeasureTextEx(font, "High Score: ", fontSize * 0.4f, spacing).x;
	DrawTextEx(font, TextFormat("%01i", highScore), position, fontSize * 0.4f, spacing, color);

	position.x += MeasureTextEx(font, TextFormat("%01i", highScore), fontSize * 0.4f, spacing).x;
	DrawTextEx(font, "M", position, fontSize * 0.4f, spacing, color);
}
