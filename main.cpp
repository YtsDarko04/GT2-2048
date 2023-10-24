#include <iostream>
using namespace std;


struct Cell
{
	int valeur;
	int position;
	bool estPlein;
} gameGrid[4][4];

int main() {

	Cell mycell;
	mycell.valeur = 1;
	mycell.position = 1;
	mycell.estPlein = true;

	cout<<"mycell.valeur ="<< mycell.valeur
};
