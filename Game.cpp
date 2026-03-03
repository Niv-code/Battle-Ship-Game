#include "Game.hpp"
#include <iostream>
void Game::setup()
{
    player1->placeAllShips();
    player2->placeAllShips();
}

void Game::announceWinner()
{
    if (player1->allShipsSunk())
    {
        std::cout << player2->getPlayerName() << " is the winner!" << std::endl;
    }
    else if (player2->allShipsSunk())
    {
        std::cout << player1->getPlayerName() << " is the winner!" << std::endl;
    }
}  
bool Game::isGameOver() const
{
    return player1->allShipsSunk() || player2->allShipsSunk();
}
void Game::start()
{
    while (true)
    {
        std::cout << "\n=== " << player1->getPlayerName() << "'s TURN ===" << std::endl;
        player1->makeMove(player2);
        std::cout << "\n" << player1->getPlayerName() << "'s GRID:" << std::endl;
        player1->getGrid().printGrid();
        
        if (isGameOver())
            break;

        std::cout << "\n=== " << player2->getPlayerName() << "'s TURN ===" << std::endl;
        player2->makeMove(player1);
        std::cout << "\n" << player2->getPlayerName() << "'s GRID:" << std::endl;
        player2->getGrid().printGrid();
        
        if (isGameOver())
            break;
    }

    announceWinner();
}
