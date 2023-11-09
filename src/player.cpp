#include "player.h"

void playerMovement(Player& player, int screenHeight)
{
	if (IsKeyDown(KEY_W) && player.pos.y > 0)
	{
		player.pos.y -= player.speed * GetFrameTime();
	}

	if (IsKeyDown(KEY_S) && player.pos.y < screenHeight - player.height)
	{
		player.pos.y += player.speed * GetFrameTime();
	}
}

