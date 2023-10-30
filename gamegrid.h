#pragma once

#include "cell.h"

using namespace std;

class GameGrid
{

public:
    
    GameGrid();
    vector<vector<Cell>> grid;

    void createGrid();

    void display();

    void placementInit();

    void rPlacementCell();

    void updateMergedCells();
};