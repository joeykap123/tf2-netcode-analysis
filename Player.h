#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Position.h"

struct Player 
{
    std::string username;
    std::vector<Position> playerPositionList;
    std::vector<Position> serverPositionList;
    Position playerPos;
    Position serverPos;
};

string getPlayerName(const Player& playr);

Position getPlayerPosition(const Player& playr);

Position getServerPosition(const Player& playr);

vector getPlayerPositionList(const Player& playr);

void updatePlayerPositionList(Player& playr, const Position& newPos);

void updateServerPositionList(Player& playr, const Position& newPos);

// Need to implement Player latency, etc.


#endif player_h