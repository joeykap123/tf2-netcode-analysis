#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Position.h"

struct Player 
{
    std::string username;
    double velocity;

    // Client Side Components
    std::vector<Position> playerPositionList;
    Position playerPos;

    // Server Side Components
    std::vector<Position> serverPositionList;
    Position serverPos;
    
    // Network Condition Components
    NetworkCondition net;
};

string getPlayerName(const Player& playr);

Position getPlayerPosition(const Player& playr);

Position getServerPosition(const Player& playr);

vector getPlayerPositionList(const Player& playr);

void updatePlayerPositionList(Player& playr, const Position& newPos);

void updateServerPositionList(Player& playr, const Position& newPos);

#endif player_h
