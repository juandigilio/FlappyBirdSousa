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
	 
	extern Texture2D menuBackground;
	extern Texture2D creditsBackground;
	extern Texture2D backParallax;
	extern Texture2D middleParallax;
	extern Texture2D frontParallax;
	extern Texture2D resume;
	extern Texture2D menu;
	extern Texture2D resumeSelected;
	extern Texture2D menuSelected;
	extern Texture2D idlePlayer;
	extern Texture2D jumpingPlayer;

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
	 
	extern float scrollingBack;
	extern float scrollingMid;
	extern float scrollingFore;
	 
	extern int middleButtons;

	extern bool firstTime;

	extern GameSceen actualSceen;
}

