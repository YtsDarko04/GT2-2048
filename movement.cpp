#include <iostream>
#include <vector>
#include <stdlib.h>

#include "cell.h"
#include "gamegrid.h"
#include "movement.h"

using namespace std;

Movement::Movement() {
    moved = false;
};

void Movement::movementRight(vector<vector<Cell>>& grid) {
    for (int i = 0; i < 4; i++) {
        for (int j = 3; j > 0; j--) {
            if (grid[i][j].isEmptyCell() == true) {
                for (int k = j - 1; k >= 0; k--) {
                    if (grid[i][k].isEmptyCell() == false) {
                        grid[i][j].setValue(grid[i][k].getValue());
                        grid[i][k].resetEmptyCell();
                        moved = true;
                        break;
                    }
                }
            }
        }
    }
};
void Movement::movementLeft(vector<vector<Cell>>& grid) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (grid[i][j].isEmptyCell() == true) {
                for (int k = j + 1; k < 4; k++) {
                    if (grid[i][k].isEmptyCell() == false) {
                        grid[i][j].setValue(grid[i][k].getValue());
                        grid[i][k].resetEmptyCell();
                        moved = true;
                        break;
                    }
                }
            }
        }
    }
};
void Movement::movementDown(vector<vector<Cell>>& grid) {
    for (int i = 3; i >= 0; i--) {
        for (int j = 0; j < 4; j++) {
            if (grid[i][j].isEmptyCell() == true) {
                for (int k = i - 1; k >= 0; k--) {
                    if (grid[k][j].isEmptyCell() == false) {
                        grid[i][j].setValue(grid[k][j].getValue());
                        grid[k][j].resetEmptyCell();
                        moved = true;
                        break;
                    }
                }
            }
        }
    }
};
void Movement::movementUp(vector<vector<Cell>>& grid) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (grid[i][j].isEmptyCell() == true) {
                for (int k = i + 1; k < 4; k++) {
                    if (grid[k][j].isEmptyCell() == false) {
                        grid[i][j].setValue(grid[k][j].getValue());
                        grid[k][j].resetEmptyCell();
                        moved = true;
                        break;
                    }
                }
            }
        }
    }
};