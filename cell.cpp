#include "cell.h"

Cell::Cell () {
    m_value = 0;
    m_isEmpty = true;
    m_isMerged = false;
}

void Cell::setValue(int value) {
    m_value = value;
    m_isEmpty = false;
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