#pragma once
#include "raylib/raylib.h"

void parallaxUpdate(float& scrollingBack, float& scrollingMid, float& scrollingFore, Texture2D& backParallax, Texture2D& middleParallax, Texture2D& frontParallax);
void parallaxDraw(float& scrollingBack, float& scrollingMid, float& scrollingFore, Texture2D& backParallax, Texture2D& middleParallax, Texture2D& frontParallax);
void staticParallaxDraw(Texture2D backParallax, Texture2D middleParallax, Texture2D frontParallax);