#include <iostream>

using namespace std;

class Cell
{
private:
	int valeur;
	int position;
	bool estPlein;
};



class GameGrid
{
public:
	GameGrid(); //constructor
	~GameGrid(); //destructor

	void createGrid() {
		int i;
		int j;
		for (i = 0; i < 4; i++) {
			cout << "0 ";
			for (j = 0; j < 3; j++) {
				cout << "0 ";
			}
			cout << "\n";
		}
	};

	void update() {
	}

	void placementInit(){
	}



};

GameGrid::GameGrid() //instancier
{
}

GameGrid::~GameGrid() //desinstancier
{
}
int main() 
{
	Cell mycell;

	GameGrid jeu;
	jeu.createGrid();
}



