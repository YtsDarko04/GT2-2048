#include <iostream>
#include <SDL.h>

#include "gameobject.h"

using namespace std;

GameObject::GameObject(int x, int y, int width, int height, SDL_Renderer* renderer) : rect({ x, y, width, height }), renderer(renderer) {
}

void GameObject::SetPosition(int x, int y) {
    rect.x = x;
    rect.y = y;
}

void GameObject::SetSize(int width, int height) {
    rect.w = width;
    rect.h = height;
}

void GameObject::Render(SDL_Renderer* renderer) {
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}