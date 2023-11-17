#include "player.h"

void playerMovement(Player& player)
{
	if (IsKeyPressed(KEY_SPACE) && player.pos.y > 0)
	{
		player.velocity.y = player.jumpForce;
        player.isJumping = true;
	}

	player.velocity.y += player.gravity * GetFrameTime();
	player.pos.y += player.velocity.y * GetFrameTime();

    if (player.isJumping && player.velocity.y > 0)
    {
        player.isJumping = false;
    }
}

Texture2D changeTexture(Texture2D jumpingPlayer, Texture2D idlePlayer, Player player)
{
    if (player.isJumping == true)
    {
        return jumpingPlayer;
    }
    else
    {
        return idlePlayer;
    }
}
