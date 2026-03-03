#pragma once
#include <cstring>
#include "Ship.hpp"
#include "Grid.hpp"

class Player
{
protected:
    char* PlayerName;
    Ship* ships[5];
    Grid grid;
public:
    Player(const char* name);
    virtual ~Player();
    
    void createFleet();
    virtual void placeAllShips();
    virtual void makeMove(Player* opponent);

    Ship* findShip(int row, int col);

    bool allShipsSunk() const;

    Grid& getGrid() { return grid; }
    const Grid& getGrid() const { return grid; }

    Ship* getShip(int i) { return ships[i]; }

    char* getPlayerName() {return PlayerName; }
};

