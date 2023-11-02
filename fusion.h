#pragma once

#include "movement.h"

class Fusion {
public:
    Fusion();
    void fusionRight(vector<vector<Cell*>>& grid);

    void fusionLeft(vector<vector<Cell*>>& grid);

    void fusionDown(vector<vector<Cell*>>& grid);

    void fusionUp(vector<vector<Cell*>>& grid);
};