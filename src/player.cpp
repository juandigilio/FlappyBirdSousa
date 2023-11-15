#include "player.h"

void playerMovement(Player& player)
{
	if (IsKeyDown(KEY_SPACE) && player.pos.y > 0)
	{
		player.velocity.y = player.jumpForce;
	}

	player.velocity.y += player.gravity * GetFrameTime();
	player.pos.y += player.velocity.y * GetFrameTime();

	if (player.pos.y <= 0)
	{
		player.jumpForce = 0.0f;
		player.pos.y = 0;
	}
	else 
	{
		player.jumpForce = -400.0f;
	}
}

