#include "parallax.h"

#include "gameData.h"

using namespace Globals;

void updateParallax()
{
    scrollingBack -= 300.0f * GetFrameTime();
    scrollingMid -= 500.0f * GetFrameTime();
    scrollingFore -= 800.0f * GetFrameTime();

    if (scrollingBack <= -backParallax.width)
    {
        scrollingBack = 0;
    }

    if (scrollingMid <= -middleParallax.width)
    {
        scrollingMid = 0;
    }

    if (scrollingFore <= -frontParallax.width)
    {
        scrollingFore = 0;
    }
}

void drawParallax()
{
    Vector2 uno = { scrollingBack , 0 };
    Vector2 dos = { backParallax.width + scrollingBack, 0 };

    Vector2 tres = { scrollingMid, 0 };
    Vector2 cuatro = { middleParallax.width + scrollingMid, 0 };

    Vector2 cinco = { scrollingFore, 0 };
    Vector2 seis = { frontParallax.width + scrollingFore, 0 };

    DrawTextureEx(backParallax, uno, 0.0f, 1.0f, WHITE);
    DrawTextureEx(backParallax, dos, 0.0f, 1.0f, WHITE);

    DrawTextureEx(middleParallax, tres, 0.0f, 1.0f, WHITE);
    DrawTextureEx(middleParallax, cuatro, 0.0f, 1.0f, WHITE);

    DrawTextureEx(frontParallax, cinco, 0.0f, 1.0f, WHITE);
    DrawTextureEx(frontParallax, seis, 0.0f, 1.0f, WHITE);
}

void staticParallaxDraw()
{
    DrawTextureEx(backParallax, { 0.0f , 0 }, 0.0f, 1.0f, WHITE);

    DrawTextureEx(middleParallax, { 0.0f, 0 }, 0.0f, 1.0f, WHITE);

    DrawTextureEx(frontParallax, { 0.0f, 0 }, 0.0f, 1.0f, WHITE);
}