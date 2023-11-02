#include "image.h"
#include <iostream>

#include <cmath>
#include <string>

Image::Image(SDL_Renderer* renderer) 
{
	m_oTextures.resize(12);

	SDL_Surface* image = SDL_LoadBMP("img/0.bmp");
	m_oTextures[0] = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);

	for (int i = 1; i < 12; ++i) 
	{
		std::string path = "img/" + std::to_string((int) pow(2, i)) + ".bmp";
		SDL_Surface* image = SDL_LoadBMP(path.c_str());
		m_oTextures[i] = SDL_CreateTextureFromSurface(renderer, image);
		SDL_FreeSurface(image);
	}
}

SDL_Texture* Image::getImage(int value)
{
	int index = 0;

	if (value > 0/* && value < m_oTextures.size()*/)
		index = log2(value);

	return m_oTextures[index];
	
}
