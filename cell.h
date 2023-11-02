#pragma once
#include <SDL.h>
#include "image.h"
#include "GameObject.h"

class Cell : public GameObject{
private:
    int m_value;
    bool m_isEmpty;
    bool m_isMerged;
    struct SDL_Surface;
    Image* images;

public:
    Cell(int x, int y, int width, int height, SDL_Renderer* renderer);

    void setValue(int value);

    int getValue();

    bool isEmptyCell();

    bool setEmptyCell();

    void resetEmptyCell();

    void setMergedCell();

    void resetMergedCell();

    bool isMergedCell();
};