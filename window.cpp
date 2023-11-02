#include <iostream>
#include <SDL.h>

using namespace std;

class Window {
public:
    Window(const char* title, int width, int height) : window(NULL), renderer(NULL) {
        if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
            cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
            exit(1);
        }

        window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

        if (!window || !renderer) {
            cout << "Error creating window or renderer: " << SDL_GetError() << std::endl;
            exit(1);
        }
    }

    SDL_Renderer* GetRenderer() const {
        return renderer;
    }

    void Clear() {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
    }

    void Present() {
        SDL_RenderPresent(renderer);
    }

    ~Window() {
        if (renderer) {
            SDL_DestroyRenderer(renderer);
        }
        if (window) {
            SDL_DestroyWindow(window);
        }
        SDL_Quit();
    }

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};