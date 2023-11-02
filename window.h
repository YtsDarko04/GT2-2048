#pragma once
#include <iostream>
#include <SDL.h>

using namespace std;

class Window {
public:

    Window(const char* title, int width, int height) : window(NULL), renderer(NULL) {};

    SDL_Renderer* GetRenderer() const;

    void Clear();
    
    void Present();

    ~Window();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};