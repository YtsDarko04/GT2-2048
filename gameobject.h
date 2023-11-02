#pragma once
#include <iostream>
#include <SDL.h>

using namespace std;

class GameObject {
public:
    GameObject(int x, int y, int width, int height, SDL_Renderer* renderer);

    void SetPosition(int x, int y);

    void SetSize(int width, int height);

    void Render(SDL_Renderer* renderer);

protected:
    SDL_Rect rect;
    SDL_Texture* texture;
    SDL_Renderer* renderer;
};