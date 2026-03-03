#include "AiPlayer.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

void AiPlayer::placeAllShips()
{
    for (int i = 0; i < 5; i++)
    {
        int row = 0, col = 0;
        bool horizontal = true;
        
        while (true)
        {
            row = std::rand() % 10;
            col = std::rand() % 10;
            horizontal = (std::rand() % 2 == 1); 

            if (grid.canPlaceShip(row, col, ships[i]->getShipSize(), horizontal))
                break;
        }

        grid.placeShip(row, col, ships[i]->getShipSize(), horizontal, 'S');

        ships[i]->setDirection(horizontal); 
        ships[i]->setRow(row);
        ships[i]->setCol(col);
    }
}


void AiPlayer::makeMove(Player* opponent)
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

        char cell = opponent->getGrid().getCell(row, col);

        if (cell != 'X' && cell != 'M') {
            break;
        }
    }

    char cell = opponent->getGrid().getCell(row, col);

    if (cell == 'S')
    {
        Ship* hitShip = opponent->findShip(row, col);

        if (hitShip) {
            hitShip->takeHit();
        } else {
            std::cerr << "Warning: grid shows ship but findShip returned nullptr.\n";
        }

        opponent->getGrid().markHit(row, col);
    }
    else
    {
        opponent->getGrid().markMiss(row, col);
    }
}
