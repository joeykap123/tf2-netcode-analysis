#include <iostream>
#include <Player.h>
#include <Position.h>

string Player::getPlayerName(const Player& playr) 
{
    return playr.username;
}

Position Player::getPlayerPosition(const Player& playr)
{
    return playr.playerPos;
}

Position Player::getServerPosition(const Player& playr) 
{
    return playr.serverPos;
}

vector Player::getPlayerPositionList(const Player& playr) 
{
    return playr.playerPositionList
}

void Player::updatePlayerPositionList(Player& playr, const Position& newPos)
{
    playr.playerPositionList.push_back(playr.playerPos);
    playr.playerPos = newPos;
}

void Player::updateServerPositionList(Player& playr, const Position& newPos)
{   
    playr.serverPositionList.push_back(playr.serverPos);
    playr.serverPos = newPos;
}