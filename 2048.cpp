#include <iostream>
#include <vector>
#include <stdlib.h>
#include <random>
#include <conio.h>

#include "fusion.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

using namespace std;

int main(int argc, char** argv)
{
    bool badKey = true;
    Movement move;
    GameGrid jeu;
    Fusion fusion;
    //Defeate gameover;
    jeu.createGrid(); //creation de la grid
    jeu.placementInit(); //placement des deux premières valeurs 
    while (true) {
        if (move.moved == true) {
            jeu.updateMergedCells();
            jeu.rPlacementCell();
            move.moved = false;
        }
        system("cls");
        jeu.display();
        badKey = false;
        int c = 0;
        switch ((c = _getch())) {
            case KEY_UP:
                move.movementUp(jeu.grid);
                fusion.fusionUp(jeu.grid);
                break;
            case KEY_DOWN:
                move.movementDown(jeu.grid);
                fusion.fusionDown(jeu.grid);
                break;
            case KEY_RIGHT:
                move.movementRight(jeu.grid);
                fusion.fusionRight(jeu.grid);
                break;
            case KEY_LEFT:
                move.movementLeft(jeu.grid);
                fusion.fusionLeft(jeu.grid);
                break;
            default:
                badKey = true;
                break;
        }
        /*if (gameover.GameOver(jeu.grid) == true) {
            jeu.display();
            cout << "Jeu termine";
            break;
        }*/
    }

    return 0;
}