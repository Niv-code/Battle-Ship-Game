#include "HumanPlayer.hpp"
#include <iostream>
#include <cstdlib>

void HumanPlayer::placeAllShips()
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

void HumanPlayer::makeMove(Player* opponent)
{
    if (!opponent)
        return;

    int row = 0, col = 0;

    while (true)
    {
        row = std::rand() % 10;
        col = std::rand() % 10;

        char cell = opponent->getGrid().getCell(row, col);

        if (cell != 'X' && cell != 'M')
        {
            break;
        }
    }

    char cell = opponent->getGrid().getCell(row, col);

    if (cell == 'S')
    {
        Ship* hitShip = opponent->findShip(row, col);
        if (hitShip)
            hitShip->takeHit();

        opponent->getGrid().markHit(row, col);
        std::cout << getPlayerName() << " hit at (" << row << ", " << col << ")!" << std::endl;
    }
    else
    {
        opponent->getGrid().markMiss(row, col);
        std::cout << getPlayerName() << " missed at (" << row << ", " << col << ")." << std::endl;
    }
}
