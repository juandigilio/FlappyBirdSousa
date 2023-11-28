#pragma once

#include "raylib/raylib.h"

enum class GameSceen
{
	Menu,
	Game,
	Pause,
	Credits,
	Exit
};

namespace Globals
{
	extern const int screenWidth;
	extern const int screenHeight;
	 
	extern const int minObstacleHeight;
	extern const int maxObstacleHeight;
	 
	extern int highScore;
	extern double speedometer;

	extern Texture2D menuBackground;
	extern Texture2D creditsBackground;
	extern Texture2D backParallax;
	extern Texture2D middleParallax;
	extern Texture2D frontParallax;
	extern Texture2D resume;
	extern Texture2D menu;
	extern Texture2D resumeSelected;
	extern Texture2D menuSelected;
	
	extern Sound jump1;
	extern Sound creditsSound;
	extern Sound dead;
	extern Sound menuSelectedSound;
	extern Sound menuUnselectedSound;
	extern Sound shoot;
	extern Sound win;

	extern Font font;
	extern float fontSize;

	extern Rectangle resumePos;
	extern Rectangle menuPos;

	extern int menuBackgroundWidth;
	extern int menuBackgroundHeight;
	extern Rectangle menuSource;
	extern Rectangle menuDest;
	 
	extern bool newScene;
	extern bool multiPlayer;
	extern bool exitProgram;
	extern bool isGamePaused;
	extern bool firstTime;
	extern bool isClicking;

	extern float scrollingBack;
	extern float scrollingMid;
	extern float scrollingFore;
	 
	extern int middleButtons;



	extern GameSceen actualSceen;
}

