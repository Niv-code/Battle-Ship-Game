#include <iostream>
#include <cstdlib>   
#include <ctime>     
#include "Game.hpp"
#include "HumanPlayer.hpp"
#include "AiPlayer.hpp"

int main() {
    
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
   
    Player* p1 = new HumanPlayer("Human");
    Player* p2 = new AiPlayer("Computer");
    
    Game game(p1, p2);
   
    game.setup();

    std::cout << "\n=== HUMAN PLAYER GRID ===" << std::endl;
    p1->getGrid().printGrid();
    
    std::cout << "\n=== AI PLAYER GRID ===" << std::endl;
    p2->getGrid().printGrid();

    game.start();
    return 0;
}
