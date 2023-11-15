#include "parallax.h"

void parallaxUpdate(float& scrollingBack, float& scrollingMid, float& scrollingFore, Texture2D& backParallax, Texture2D& middleParallax, Texture2D& frontParallax)
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

void parallaxDraw(float& scrollingBack, float& scrollingMid, float& scrollingFore, Texture2D& backParallax, Texture2D& middleParallax, Texture2D& frontParallax)
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