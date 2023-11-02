#include <iostream>
#include <vector>
#include <stdlib.h>
#include <random>

#include "gamegrid.h"

using namespace std;

GameGrid::GameGrid() {};

void GameGrid::createGrid() {
    grid.resize(4);
    for (int j = 0; j < 4; j++) {
        grid[j].resize(4);
        for (int i = 0; i < 4; ++i) 
        {
            int x = 0;
            int y = 0;
            grid[j][i] = new Cell(x, y, 150, 150, renderer);
            x = x + 150;
            y = y + 150;
        }
    }
};

void GameGrid::display() {

    for (int i = 0; i < 16; i++) {
        int row = i / 4;
        int col = i % 4;

        int x = col * (150 + 5) + 5;
        int y = row * (150 + 5) + 5;
        
        }
}

void GameGrid::placementInit() {
    //init seed

    srand(time(NULL));
    random_device randomNumber;
    default_random_engine generator(randomNumber());
    bernoulli_distribution distribution(0.8);

    int i = 0;

    while (i < 2) {
        int rCell = rand() % 16;
        int rValue = distribution(generator) ? 2 : 4;
        grid[rCell / 4][rCell % 4]->setValue(rValue);
        i++;
    }
}

void GameGrid::rPlacementCell() {
    random_device randomNumber;
    default_random_engine generator(randomNumber());
    bernoulli_distribution distribution(0.6);
    int rCell = rand() % 16;
    int rValue = distribution(generator) ? 2 : 4;
    if (grid[rCell / 4][rCell % 4]->isEmptyCell() == true) {
        grid[rCell / 4][rCell % 4]->setValue(rValue);
    }
    else {
        cout << "valeur détecte dans la case selectionnee, relancement de la fonction \n";
        rPlacementCell();
    }
}

void GameGrid::updateMergedCells() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            grid[i][j]->resetMergedCell();
        }
    }
}