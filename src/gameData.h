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
	 
	extern Texture2D backParallax;
	extern Texture2D middleParallax;
	extern Texture2D frontParallax;
	extern Texture2D menuUnselectedButton;
	extern Texture2D menuSelectedButton;
	extern Texture2D playUnselectedButton;
	extern Texture2D playSelectedButton;
	extern Texture2D creditsUnselectedButton;
	extern Texture2D creditsSelectedButton;
	extern Texture2D exitUnselectedButton;
	extern Texture2D exitSelectedButton;
	extern Texture2D creditsParallaxUnselectedButton;
	extern Texture2D creditsParallaxSelectedButton;
	extern Texture2D creditsNachoUnselectedButton;
	extern Texture2D creditsNachoSelectedButton;
	extern Texture2D resumeUnselectedButton;
	extern Texture2D resumeSelectedButton;
	extern Texture2D pause;
	extern Texture2D idlePlayer;
	extern Texture2D jumpingPlayer;
	 
	extern bool newScene;
	extern bool exitProgram;
	extern bool isGamePaused;
	 
	extern float scrollingBack;
	extern float scrollingMid;
	extern float scrollingFore;
	 
	extern int middleButtons;

}

