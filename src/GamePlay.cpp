#include "GamePlay.h"



void resetStats(Player& player, Obstacles& topObstacles, Obstacles& bottomObstacles)
{
	setPlayer(player);
	setObstacles(topObstacles, bottomObstacles);
}