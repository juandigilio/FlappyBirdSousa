#pragma once
#include "raylib/raylib.h"
#include "scenes.h"
#include "buttons.h"
#include "parallax.h"

void drawMenu(GameScenes& actualScene, int screenWidth, Texture2D playUnselectedButton, Texture2D playSelectedButton, Texture2D creditsUnselectedButton, Texture2D creditsSelectedButton, Texture2D exitUnselectedButton, Texture2D exitSelectedButton, Texture2D backParallax, Texture2D middleParallax, Texture2D frontParallax);
