#include <iostream>
#include <vector>
#include <stdlib.h>

#include "defeate.h"

using namespace std;

bool Defeate::GameOver(vector<vector<Cell>>& grid) {
    bool isGameover = false;
    vector<int> GameOverLst;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j].isEmptyCell() == false) {
                if ( i+1<3 && grid[i][j].getValue() == grid[i + 1][j].getValue() || grid[i + 1][j].isEmptyCell() == true) {
                    //isGameover = false;
                    GameOverLst.push_back(0);
                }
                else if (j+1<3 && grid[i][j].getValue() == grid[i][j + 1].getValue() || grid[i][j + 1].isEmptyCell() == true) {
                    //isGameover = false;
                    GameOverLst.push_back(0);
                }
                else {
                    //isGameover = true;
                    GameOverLst.push_back(1);
                }
            }
            if (GameOverLst.empty()){
                for (int i = 0; i < GameOverLst.size(); i++) {
					if (GameOverLst[i] == 0) {
						isGameover = false;
					}
					else {
						isGameover = true;
					}
                }
				
            }
        }
    }
    return isGameover;
};