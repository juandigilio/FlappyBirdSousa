#include "player.h"

void playerMovement(Player& player)
{
	if (IsKeyPressed(KEY_SPACE) && player.pos.y > 0)
	{
		player.velocity.y = player.jumpForce;
	}

	player.velocity.y += player.gravity * GetFrameTime();
	player.pos.y += player.velocity.y * GetFrameTime();
}

void checkMovementInput(Player& player)
{
    if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
    {
        player.velocity.y = player.jumpForce;
        player.isJumping = true;
    }
}

void changeTexture(Player& player, Texture2D jumpingPlayer, Texture2D idlePlayer)
{
    if (player.isJumping == true)
    {
        player.texture = jumpingPlayer;
    }
    else
    {
        player.texture = idlePlayer;
    }
}
