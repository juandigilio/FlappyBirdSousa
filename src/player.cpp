#include "player.h"

#include "gameData.h"

#include <iostream>

using namespace std;

using namespace Globals;

void setPlayer(Player& player)
{
    player.pos.x = 100;
    player.pos.y = static_cast<float>(screenHeight / 2);
    player.speed = 400;
    player.width = 60;
    player.height = 60;
    player.velocity = { 0, 0 };
    player.gravity = 600.0;
    player.jumpForce = -400.0f;
    player.isColliding = false;
    player.isJumping = false;
    player.frame = 0;

    player.textureIddle = LoadTexture("assets/gamePlay/ass.png");
    player.textureJumping = LoadTexture("assets/gamePlay/assSprite.png");
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
        player.frame = 0;
        player.lastFrame = GetTime();
	}

   /* if (player.isJumping && player.velocity.y > 0)
    {
        player.isJumping = false;
    }*/
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

void updatePlayer(Player& player, Obstacles& topObstacles, Obstacles& bottomObstacles)
{
    movePlayer(player);

    if (checkCollision(player, topObstacles) || checkCollision(player, bottomObstacles))
    {
        player.isColliding = true;
    }
    else
    {
        if (player.pos.y > screenHeight)
        {
            player.isColliding = true;
        }
    }
}

void drawPlayer(Player& player)
{
    //DrawTexture(player.texture, static_cast<int>(player.pos.x), static_cast<int>(player.pos.y), WHITE);
    Vector2 origin = { static_cast<float>(player.textureIddle.width / 2), static_cast<float>(player.textureIddle.height / 2) };
    
    float jumpingTextureWidth = 93.0f;
    float jumpingTextureHeight = 94.0f;

    if (player.isJumping)
    {
        Rectangle dest = { player.GetCenter().x, player.GetCenter().y, jumpingTextureWidth, jumpingTextureHeight };

        switch (player.frame)
        {
            case 0:
            {
                player.source = { 0, 0, jumpingTextureWidth, jumpingTextureHeight };
                DrawTexturePro(player.textureJumping, player.source, dest, origin, 0.0f, RAYWHITE);
                break;
            }
            case 1:
            {
                player.source = { jumpingTextureWidth, 0, jumpingTextureWidth, jumpingTextureHeight };
                DrawTexturePro(player.textureJumping, player.source, dest, origin, 0.0f, RAYWHITE);
                break;
            }
            case 2:
            {
                player.source = { jumpingTextureWidth * 2, 0, jumpingTextureWidth, jumpingTextureHeight };
                DrawTexturePro(player.textureJumping, player.source, dest, origin, 0.0f, RAYWHITE);
                break;
            }
            case 3:
            {
                player.source = { jumpingTextureWidth * 3, 0, jumpingTextureWidth, jumpingTextureHeight };
                DrawTexturePro(player.textureJumping, player.source, dest, origin, 0.0f, RAYWHITE);
                break;
            }
            case 4:
            {
                player.source = { jumpingTextureWidth * 4, 0, jumpingTextureWidth, jumpingTextureHeight };
                DrawTexturePro(player.textureJumping, player.source, dest, origin, 0.0f, RAYWHITE);
                break;
            }
        }

        double elapsedTime = GetTime() - player.lastFrame;

        //cout << "elapsed: " << elapsedTime << endl;

        if (elapsedTime > 0.07f)
        {
            cout << "frame: " << player.frame << endl;
            player.frame++;

            player.lastFrame = GetTime();

            if (player.frame > 4)
            {
                player.isJumping = false;
                player.frame = 0;
            }
        }
    }
    else
    {
        Rectangle dest = { player.GetCenter().x, player.GetCenter().y, static_cast<float>(player.textureIddle.width), static_cast<float>(player.textureIddle.height) };

        player.source = { 0, 0, static_cast<float>(player.textureIddle.width), static_cast<float>(player.textureIddle.height) };
       
        DrawTexturePro(player.textureIddle, player.source, dest, origin, 0.0f, RAYWHITE);
    }
}