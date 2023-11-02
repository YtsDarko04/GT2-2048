#include <iostream>
#include <vector>
#include <stdlib.h>

#include "fusion.h"

using namespace std;

Fusion::Fusion() {};

void Fusion::fusionRight(vector<vector<Cell*>>& grid) {
    for (int i = 0; i < 4; i++) {
        for (int j = 3; j > 0; j--) {
            if (grid[i][j]->isEmptyCell() == false) { //grid[0][3] est remplie -> oui
                if (grid[i][j - 1]->isEmptyCell() == false) { //grid[0][2] est remplie -> oui
                    if (grid[i][j]->getValue() == grid[i][j - 1]->getValue() && grid[i][j]->isMergedCell() == false) {
                        grid[i][j]->setValue(grid[i][j]->getValue() * 2);
                        grid[i][j - 1]->resetEmptyCell();
                        grid[i][j]->setMergedCell();
                        break;
                    }
                }
            }
        }
    }
};

void Fusion::fusionLeft(vector<vector<Cell*>>& grid) {
    for (int i = 0; i < 4; i++) {
        for (int j = 3; j > 0; j--) {
            if (grid[i][j]->isEmptyCell() == false) { //grid[0][3] est remplie -> oui
                if (grid[i][j - 1]->isEmptyCell() == false) { //grid[0][2] est remplie -> oui
                    if (grid[i][j]->getValue() == grid[i][j - 1]->getValue() && grid[i][j - 1]->isMergedCell() == false) {
                        grid[i][j - 1]->setValue(grid[i][j - 1]->getValue() * 2);
                        grid[i][j]->resetEmptyCell();
                        grid[i][j - 1]->setMergedCell();
                        break;
                    }
                }
            }
        }
    }
};

void Fusion::fusionDown(vector<vector<Cell*>>& grid) {
    for (int i = 3; i > 0; i--) {
        for (int j = 0; j < 4; j++) {
            if (grid[i][j]->isEmptyCell() == false) { //grid[0][3] est remplie -> oui
                if (grid[i - 1][j]->isEmptyCell() == false) { //grid[0][2] est remplie -> oui
                    if (grid[i][j]->getValue() == grid[i - 1][j]->getValue() && grid[i][j]->isMergedCell() == false) {
                        grid[i][j]->setValue(grid[i][j]->getValue() * 2);
                        grid[i - 1][j]->resetEmptyCell();
                        grid[i][j]->setMergedCell();
                        break;
                    }
                }
            }
        }
    }
};

void Fusion::fusionUp(vector<vector<Cell*>>& grid) {
    for (int i = 3; i > 0; i--) {
        for (int j = 0; j < 4; j++) {
            if (grid[i - 1][j]->isEmptyCell() == false) { //grid[0][3] est remplie -> oui
                if (grid[i - 1][j]->isEmptyCell() == false) { //grid[0][2] est remplie -> oui
                    if (grid[i][j]->getValue() == grid[i - 1][j]->getValue() && grid[i - 1][j]->isMergedCell() == false) {
                        grid[i - 1][j]->setValue(grid[i - 1][j]->getValue() * 2);
                        grid[i][j]->resetEmptyCell();
                        grid[i - 1][j]->setMergedCell();
                        break;
                    }
                }
            }
        }
    }
};