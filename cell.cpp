#include "cell.h"
#include <SDL.h>

#include "image.h"

Cell::Cell(int x, int y, int width, int height, SDL_Renderer* renderer) : GameObject(x, y, width, height, renderer)
{
    m_value = 0;
    m_isEmpty = true;
    m_isMerged = false;
}

void Cell::setValue(int value) {
    m_value = value;
    m_isEmpty = false;

    texture = images->getImage(m_value);
}

int Cell::getValue() {
    return m_value;
}

bool Cell::isEmptyCell() {
    return m_isEmpty;
}

bool Cell::setEmptyCell() {
    return m_isEmpty = true;
}

void Cell::resetEmptyCell() {
    m_isEmpty = true;
    m_value = 0;
}

void Cell::setMergedCell() {
    m_isMerged = true;
}

void Cell::resetMergedCell() {
    m_isMerged = false;
}

bool Cell::isMergedCell() {
    return m_isMerged;
}