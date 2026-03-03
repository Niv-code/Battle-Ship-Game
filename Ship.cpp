#include<iostream>
#include"Ship.hpp"

void Ship::takeHit()
{
    hitsTaken++;
    std::cout << name << " got hit!" << std::endl;
}

bool Ship::isSunk() const
{
    return hitsTaken >= size;
}



