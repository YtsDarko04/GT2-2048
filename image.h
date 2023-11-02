#pragma once
#include <iostream>
#include <SDL.h>

#include <vector>

using namespace std;

class Image {

public :

	vector<SDL_Texture*> m_oTextures;

	Image(SDL_Renderer* renderer);
	SDL_Texture* getImage(int value);
};