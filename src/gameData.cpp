#include "gameData.h"

namespace Globals
{
	extern const int screenWidth = 1366;
	extern const int screenHeight = 768;

	extern const int minObstacleHeight = 100;
	extern const int maxObstacleHeight = 500;

	extern Texture2D menuBackground{};
	extern Texture2D creditsBackground{};
	extern Texture2D backParallax{};
	extern Texture2D middleParallax{};
	extern Texture2D frontParallax{};
	extern Texture2D resume{};
	extern Texture2D menu{};
	extern Texture2D resumeSelected{};
	extern Texture2D menuSelected{};
	extern Texture2D idlePlayer{};
	extern Texture2D jumpingPlayer{};

	extern Rectangle resumePos{};
	extern Rectangle menuPos{};

	extern int menuBackgroundWidth = screenWidth;
	extern int menuBackgroundHeight = screenHeight;
	extern Rectangle menuSource = { 0.0f, 0.0f, static_cast<float>(menuBackgroundWidth) , static_cast<float>(menuBackgroundHeight) };
	extern Rectangle menuDest = {0.0f, 0.0f, static_cast<float>(menuBackgroundWidth) , static_cast<float>(menuBackgroundHeight) };


	extern bool newScene = true;
	extern bool multiPlayer = false;
	extern bool exitProgram = false;
	extern bool isGamePaused = false;

	extern float scrollingBack = 0.0f;
	extern float scrollingMid = 0.0f;
	extern float scrollingFore = 0.0f;

	extern int middleButtons{};

	extern bool firstTime = true;

	extern GameSceen actualSceen = GameSceen::Menu;
}