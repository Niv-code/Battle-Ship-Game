#include "Player.hpp"
#include "Carrier.hpp"
#include "Battleship.hpp"
#include "Destroyer.hpp"
#include "Submarine.hpp"
#include "Cruiser.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

void Player::createFleet()
{
    ships[0] = new Carrier();
    ships[1] = new Battleship();
    ships[2] = new Destroyer();
    ships[3] = new Submarine();
    ships[4] = new Cruiser();
}
Player::Player(const char* name) : grid()
{
    PlayerName = new char[strlen(name) + 1];
    strcpy(PlayerName, name);

    createFleet();
}


Player::~Player() 
{
    delete []PlayerName;
    PlayerName = nullptr;
    for(int i = 0; i < 5; i++)
    {
        delete ships[i];
        ships[i] = nullptr;
    }
}

void Player::placeAllShips()
{
    for (int i = 0; i < 5; i++)
    {
        int row = 0, col = 0;
        bool horizontal = true;

        while (true)
        {
            row = std::rand() % 10;
            col = std::rand() % 10;
            horizontal = (std::rand() % 2 == 1);  // true=אופקי, false=אנכי

            if (grid.canPlaceShip(row, col, ships[i]->getShipSize(), horizontal))
                break;
        }

        grid.placeShip(row, col, ships[i]->getShipSize(), horizontal, 'S');

        ships[i]->setDirection(horizontal); 
        ships[i]->setRow(row);
        ships[i]->setCol(col);
    }
}


Ship* Player::findShip(int row, int col)
{
    for (int i = 0; i < 5; ++i)
    {
        Ship* s = ships[i];
        if (!s) continue;

        const int r0 = s->getRow();
        const int c0 = s->getCol();
        const int size = s->getShipSize();
        const bool horiz = s->getHorizontal(); 

        if (horiz)
        {
            if (row == r0 && col >= c0 && col < c0 + size)
                return s;
        }
        else
        {
            if (col == c0 && row >= r0 && row < r0 + size)
                return s;
        }
    }

    return nullptr;
}
void Player::makeMove(Player* opponent)
{
    if (!opponent) {
        std::cerr << "Error: opponent is nullptr.\n";
        return;
    }

    int row = 0, col = 0;

    while (true)
    {
        row = std::rand() % 10;
        col = std::rand() % 10;

        char cell = opponent->grid.getCell(row, col);

        if (cell != 'X' && cell != 'M') {
            break;
        }
    }

    char cell = opponent->grid.getCell(row, col);

    if (cell == 'S')
    {
        Ship* hitShip = opponent->findShip(row, col);

        if (hitShip) {
            hitShip->takeHit();
        } else {
            std::cerr << "Warning: grid shows ship but findShip returned nullptr.\n";
        }

        opponent->grid.markHit(row, col);
    }
    else
    {
        opponent->grid.markMiss(row, col);
    }
}

bool Player::allShipsSunk() const
{
    for(int i = 0; i < 5; i++)
    {
        if(!ships[i]->isSunk())
            return false;
    }
    return true;
}