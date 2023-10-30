#pragma once

class Cell
{
private:
    int m_value;
    bool m_isEmpty;
    bool m_isMerged;

public:
    Cell();

    void setValue(int value);

    int getValue();

    bool isEmptyCell();

    bool setEmptyCell();

    void resetEmptyCell();

    void setMergedCell();

    void resetMergedCell();

    bool isMergedCell();
};