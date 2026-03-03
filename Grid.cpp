#include "Grid.hpp"
#include <iostream>

Grid::Grid()
{
    for(int i = 0; i < 10; ++i)
    {
        for(int j = 0; j < 10; ++j)
        {
            cells[i][j] = '~';
        }
    }
}

bool Grid::isTileOccupied(int row, int col) const
{
    char currentCell = cells[row][col];

    if(currentCell == 'S' || currentCell == 'X')
        return true;

    return false;
}

bool Grid::inBounds(int row, int col, int shipSize, bool horizontal) const
{
    if (row < 0 || row >= 10 || col < 0 || col >= 10)
        return false;
    if(horizontal)
    {
        if(col + shipSize > 10)
            return false;
    }else
    {
        if(row + shipSize > 10)
            return false;
    }
    return true;
}

bool Grid::canPlaceShip(int row, int col, int shipSize, bool horizontal) const
{
    if (!inBounds(row, col, shipSize, horizontal))
        return false;

    for (int i = 0; i < shipSize; i++)
    {
        int r = row + (horizontal ? 0 : i);
        int c = col + (horizontal ? i : 0);

        if (cells[r][c] != '~')   
            return false;
    }
    return true;
}


void Grid::placeShip(int row, int col, int shipSize, bool horizontal, char symbol)
{
    for(int i = 0; i < shipSize; i++)
    {
        if(horizontal)
        {
            cells[row][col + i] = symbol;
        }
        else 
        {
            cells[row + i][col] = symbol;
        }
    }
}

void Grid::markHit(int row, int col)
{
    if (row < 0 || row >= 10 || col < 0 || col >= 10)
        return;

    if (cells[row][col] == 'X')
        return;

    cells[row][col] = 'X';
}

void Grid::markMiss(int row, int col)
{
    if (row < 0 || row >= 10 || col < 0 || col >= 10)
        return;

    if (cells[row][col] == 'M')
        return;

    cells[row][col] = 'M';
}

void Grid::printGrid() const
{
    std::cout << "  ";
    for (int col = 0; col < 10; ++col)
        std::cout << col << " ";
    std::cout << std::endl;

    for (int row = 0; row < 10; ++row)
    {
        std::cout << row << " ";
        for (int col = 0; col < 10; ++col)
        {
            std::cout << cells[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

Grid::~Grid()
{
}