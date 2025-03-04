#include "player.h"

#include "gameData.h"

#include <iostream>

using namespace std;

using namespace Globals;

void setPlayer(Player& player, Player& player2)
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
    player.totalPoints = 0;
    player.rotation = 0.0f;
    player.lastCollide = 0.0f;

    if (firstTime)
    {
        player.textureIddle = LoadTexture("Assets/GamePlay/ass.png");
        player.textureJumping = LoadTexture("Assets/GamePlay/assSprite.png");
    }
   
    if (multiPlayer)
    {
        player2.pos.x = 200;
        player2.pos.y = static_cast<float>(screenHeight / 2);
        player2.speed = 400;
        player2.width = 60;
        player2.height = 60;
        player2.velocity = { 0, 0 };
        player2.gravity = 600.0;
        player2.jumpForce = -400.0f;
        player2.isColliding = false;
        player2.isJumping = false;
        player2.frame = 0;
        player2.rotation = 0.0f;
        player2.lastCollide = 0.0f;

        if (firstTime)
        {
            player2.textureIddle = LoadTexture("Assets/GamePlay/ass2.png");
            player2.textureJumping = LoadTexture("Assets/GamePlay/assSprite2.png");
        }
    }
}

void getPlayerInput(Player& player, Player& player2)
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

	if (IsKeyPressed(KEY_LEFT_CONTROL) && player.pos.y > 0)
	{
		player.velocity.y = player.jumpForce;
        player.isJumping = true;
        player.frame = 0;
        player.lastFrame = GetTime();

        PlaySound(jump1);
	}

    if (multiPlayer)
    {
        if (player2.pos.y <= 0)
        {
            player2.jumpForce = 0.0f;
            player2.pos.y = 0;
        }
        else
        {
            player2.jumpForce = -400.0f;
        }

        if (IsKeyPressed(KEY_RIGHT_CONTROL) && player2.pos.y > 0)
        {
            player2.velocity.y = player2.jumpForce;
            player2.isJumping = true;
            player2.frame = 0;
            player2.lastFrame = GetTime();

            PlaySound(jump1);
        }
    }

    if (IsKeyPressed(KEY_ESCAPE))
    {
        PlaySound(menuUnselectedSound);
        actualSceen = GameSceen::Pause;
    }
}

static void movePlayer(Player& player)
{
    player.velocity.y += player.gravity * GetFrameTime();
    player.pos.y += player.velocity.y * GetFrameTime();
}

static bool checkCollision(Player& player, Obstacles obstacles)
{
    if (player.pos.x + player.textureIddle.width >= obstacles.pos.x + 20.0f &&
        player.pos.x <= obstacles.pos.x + obstacles.texture.width - 20.0f &&
        player.pos.y + player.textureIddle.height >= obstacles.pos.y &&
        player.pos.y <= obstacles.pos.y + obstacles.texture.height) 
    {
        return true;
    }

    return false;
}

void updatePlayer(Player& player, Player& player2, Obstacles topObstacles[], Obstacles bottomObstacles[])
{
    movePlayer(player);

    for (int i = 0; i < obstaclesQnty; i++)
    {
        if (checkCollision(player, topObstacles[i]) || checkCollision(player, bottomObstacles[i]))
        {
            player.lastCollide = static_cast<float>(GetTime());
            player2.lastCollide = static_cast<float>(GetTime());
            player.isColliding = true;

            PlaySound(dead);

            if (checkCollision(player, topObstacles[i]))
            {
                topObstacles[i].isShited = true;
            }
            else
            {
                bottomObstacles[i].isShited = true;
            }

            if (player.totalPoints > highScore)
            {
                highScore = player.totalPoints;
            }
        }
        else
        {
            if (player.pos.y > screenHeight)
            {
                player.lastCollide = static_cast<float>(GetTime());
                player2.lastCollide = static_cast<float>(GetTime());
                player.isColliding = true;

                PlaySound(dead);

                if (player.totalPoints > highScore)
                {
                    highScore = player.totalPoints;
                }
            }
        }
    }

    double elapsedTime = GetTime() - speedometer;

    if (elapsedTime > 0.4f)
    {
        player.totalPoints++;

        speedometer = GetTime();

        if (player.totalPoints - acelerator >= 20)
        {
            acelerator += 20;

            for (int i = 0; i < obstaclesQnty; i++)
            {
                topObstacles[i].speed += 40;
                bottomObstacles[i].speed += 40;
            }
        }
    }

    if (multiPlayer)
    {
        movePlayer(player2);

        for (int i = 0; i < obstaclesQnty; i++)
        {
            if (checkCollision(player2, topObstacles[i]) || checkCollision(player2, bottomObstacles[i]))
            {
                PlaySound(dead);

                if (checkCollision(player2, topObstacles[i]))
                {
                    topObstacles[i].isShited = true;
                }
                else
                {
                    bottomObstacles[i].isShited = true;
                }

                player.lastCollide = static_cast<float>(GetTime());
                player2.lastCollide = static_cast<float>(GetTime());
                player2.isColliding = true;
            }
            else
            {
                if (player2.pos.y > screenHeight)
                {
                    PlaySound(dead);

                    player.lastCollide = static_cast<float>(GetTime());
                    player2.lastCollide = static_cast<float>(GetTime());
                    player2.isColliding = true;
                }
            }
        }  
    }
}

void drawPlayer(Player& player)
{
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
       
        DrawTexturePro(player.textureIddle, player.source, dest, origin, player.rotation, RAYWHITE);
    }
}

void ShowCrash(Player& player, Player& player2, bool& animationFinished)
{
    if (player.isColliding)
    {
        player.rotation += 0.6f;
    }
    if (player.rotation >= 360.0f)
    {
        player.rotation = 0.0f;
    }
    if (GetTime() - player.lastCollide > 2.0f)
    {
        player.isColliding = false;
        animationFinished = true;
    }


    if (player2.isColliding)
    {
        player2.rotation += 0.6f;
    }
    if (player2.rotation >= 360.0f)
    {
        player2.rotation = 0.0f;
    }
    if (GetTime() - player2.lastCollide > 2.0f)
    {
        player2.isColliding = false;
        animationFinished = true;
    }
}

void unloadPlayers(Player& player1, Player& player2)
{
    UnloadTexture(player1.textureIddle);
    UnloadTexture(player1.textureJumping);
    UnloadTexture(player2.textureIddle);
    UnloadTexture(player2.textureJumping);
}
