#pragma once
#include "Player.hpp"
class AiPlayer :public Player
{

public:
    AiPlayer(const char* name) : Player(name){}
    void placeAllShips() override;
    void makeMove(Player* opponent) override;
};



