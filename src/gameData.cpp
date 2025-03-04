#include "gameData.h"

namespace Globals
{
	extern const int screenWidth = 1366;
	extern const int screenHeight = 768;

	extern const int minObstacleHeight = 100;
	extern const int maxObstacleHeight = 500;

	extern int highScore = 0;
	extern int acelerator = 0;
	extern double speedometer = 0;

	extern Texture2D menuBackground{};
	extern Texture2D creditsBackground{};
	extern Texture2D backParallax{};
	extern Texture2D middleParallax{};
	extern Texture2D frontParallax{};
	extern Texture2D resume{};
	extern Texture2D menu{};
	extern Texture2D resumeSelected{};
	extern Texture2D menuSelected{};

	extern Sound jump1{};
	extern Sound creditsSound{};
	extern Sound dead{};
	extern Sound menuSelectedSound{};
	extern Sound menuUnselectedSound{};
	extern Sound shoot{};
	
	extern Music creditsMusic{};
	extern Music gameMusic{};

	extern Font font{};
	extern float fontSize{};

	extern Rectangle resumePos = {screenWidth - 150.0f, 15.0f, 60.0f, 60.0f };
	extern Rectangle menuPos = {screenWidth - 75.0f, 15.0f, 60.0f, 60.0f };

	extern int menuBackgroundWidth = screenWidth;
	extern int menuBackgroundHeight = screenHeight;
	extern Rectangle menuSource = { 0.0f, 0.0f, static_cast<float>(menuBackgroundWidth) , static_cast<float>(menuBackgroundHeight) };
	extern Rectangle menuDest = {0.0f, 0.0f, static_cast<float>(menuBackgroundWidth) , static_cast<float>(menuBackgroundHeight) };


	extern bool newScene = true;
	extern bool multiPlayer = false;
	extern bool exitProgram = false;
	extern bool isGamePaused = false;
	extern bool firstTime = true;
	extern bool isClicking = false;

	extern float scrollingBack = 0.0f;
	extern float scrollingMid = 0.0f;
	extern float scrollingFore = 0.0f;

	extern int middleButtons{};

	extern GameSceen actualSceen = GameSceen::Menu;
}