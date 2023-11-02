#pragma once

#include "gamegrid.h"

class Movement
{
public:

    Movement();
    bool moved;

    void movementRight(vector<vector<Cell*>>& grid);

    void movementLeft(vector<vector<Cell*>>& grid);

    void movementDown(vector<vector<Cell*>>& grid);

    void movementUp(vector<vector<Cell*>>& grid);
};