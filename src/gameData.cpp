#include "gameData.h"

namespace Globals
{
	extern const int screenWidth = 1366;
	extern const int screenHeight = 768;

	extern const int minObstacleHeight = 100;
	extern const int maxObstacleHeight = 500;

	extern Texture2D backParallax{};
	extern Texture2D middleParallax{};
	extern Texture2D frontParallax{};
	extern Texture2D menuUnselectedButton{};
	extern Texture2D menuSelectedButton{};
	extern Texture2D playUnselectedButton{};
	extern Texture2D playSelectedButton{};
	extern Texture2D creditsUnselectedButton{};
	extern Texture2D creditsSelectedButton{};
	extern Texture2D exitUnselectedButton{};
	extern Texture2D exitSelectedButton{};
	extern Texture2D creditsParallaxUnselectedButton{};
	extern Texture2D creditsParallaxSelectedButton{};
	extern Texture2D creditsNachoUnselectedButton{};
	extern Texture2D creditsNachoSelectedButton{};
	extern Texture2D resumeUnselectedButton{};
	extern Texture2D resumeSelectedButton{};
	extern Texture2D pause{};
	extern Texture2D idlePlayer{};
	extern Texture2D jumpingPlayer{};

	extern bool newScene = true;
	extern bool exitProgram = false;
	extern bool isGamePaused = false;

	extern float scrollingBack = 0.0f;
	extern float scrollingMid = 0.0f;
	extern float scrollingFore = 0.0f;

	extern int middleButtons{};

	extern bool firstTime = true;
}