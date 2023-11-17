#include "player.h"

#include "gameData.h"

using namespace Globals;

void setPlayer(Player& player)
{
    player.pos.x = 100;
    player.pos.y = screenHeight / 2;
    player.speed = 400;
    player.width = 60;
    player.height = 60;
    player.velocity = { 0, 0 };
    player.gravity = 600.0;
    player.jumpForce = -400.0f;
    player.isColliding = false;
    player.isJumping = false;
}

void getPlayerInput(Player& player)
{
    if (player.pos.y <= 0)
    {
        player.jumpForce = 0.0f;
        player.pos.y = 0;
    }
    else
    {
        player.jumpForce = -400.0f;
    }

	if (IsKeyPressed(KEY_SPACE) && player.pos.y > 0)
	{
		player.velocity.y = player.jumpForce;
        player.isJumping = true;
	}

    if (player.isJumping && player.velocity.y > 0)
    {
        player.isJumping = false;
    }
}

static void movePlayer(Player& player)
{
    player.velocity.y += player.gravity * GetFrameTime();
    player.pos.y += player.velocity.y * GetFrameTime();
}

static bool checkCollision(Player player, Obstacles obstacles)
{
    if (player.pos.x + player.width >= obstacles.pos.x &&
        player.pos.x <= obstacles.pos.x + obstacles.width &&
        player.pos.y + player.height >= obstacles.pos.y &&
        player.pos.y <= obstacles.pos.y + obstacles.height) {
        return true;
    }
    return false;
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

void updatePlayer(Player& player, Obstacles& topObstacles, Obstacles& bottomObstacles)
{
    player.texture = changeTexture(jumpingPlayer, idlePlayer, player);

    movePlayer(player);

    if (checkCollision(player, topObstacles) || checkCollision(player, bottomObstacles))
    {
        player.isColliding = true;
    }
}
