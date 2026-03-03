#pragma once 
#include <cstring>
class Ship
{
private:
    char* name;
    int size;
    int hitsTaken;
    int Row;
    int Col;
    bool horizontal;
public:
    Ship(const char* shipName, int shipSize)
    : size(shipSize), hitsTaken(0), Row(0), Col(0), horizontal(true)
    {
        name = new char[strlen(shipName) + 1];
        strcpy(name, shipName);
    }
    virtual ~Ship(){delete[] name;}
    virtual void takeHit();

    bool isSunk() const;
    int getRow() const{return Row;}
    int getCol() const{return Col;}
    bool getHorizontal()const{return horizontal;}

    int getShipSize() const {return size;}
    const char* getName() const {return name;}
    
    void setDirection(bool horizontal) {this->horizontal = horizontal;}
    void setRow(int row){this->Row = row;}
    void setCol(int col){this->Col = col;}


     
    
};
