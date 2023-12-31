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

class GameObject {
public:
    GameObject(int x, int y, int width, int height, SDL_Renderer* renderer) : rect({ x, y, width, height }), renderer(renderer) {
        SDL_Surface* image = SDL_LoadBMP("img/test.bmp");
        if (!image) {
            cout << "Error loading image: " << SDL_GetError() << std::endl;
            exit(1);
        }

        texture = SDL_CreateTextureFromSurface(renderer, image);
        SDL_FreeSurface(image);

        if (!texture) {
            cout << "Error creating texture: " << SDL_GetError() << std::endl;
            exit(1);
        }
    }
    void SetPosition(int x, int y) {
        rect.x = x;
        rect.y = y;
    }

    void SetSize(int width, int height) {
        rect.w = width;
        rect.h = height;
    }

    void Render(SDL_Renderer* renderer) {
        SDL_RenderCopy(renderer, texture, NULL, &rect);
    }

private:
    SDL_Rect rect;
    SDL_Texture* texture;
    SDL_Renderer* renderer;
};

int main(int argc, char** args) {
    Window window("2048", 625, 625);

    const int numRectangles = 16;
    const int numPerRow = 4;
    const int spacing = 5;

    int rectWidth = 150;
    int rectHeight = 150;

    for (int i = 0; i < numRectangles; i++) {
        int row = i / numPerRow;
        int col = i % numPerRow;

        int x = col * (rectWidth + spacing) + spacing;
        int y = row * (rectHeight + spacing) + spacing;
        GameObject gameObject(x, y, rectWidth, rectHeight, window.GetRenderer());

        gameObject.Render(window.GetRenderer());
    }

    bool quit = false;
    SDL_Event e;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }
        // window.Clear();
        window.Present();
    }
    return 0;
}