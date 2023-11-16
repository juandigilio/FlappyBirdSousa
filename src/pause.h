#pragma once
#include "raylib/raylib.h"
#include "buttons.h"
#include "parallax.h"
#include "scenes.h"

void drawPause(GameScenes& actualScene, int screenWidth, int screenHeight, Texture2D menuUnselectedButton, Texture2D menuSelectedButton, Texture2D resumeUnselectedButton, Texture2D resumeSelectedButton, Texture2D backParallax, Texture2D middleParallax, Texture2D frontParallax, bool& isGamePaused);