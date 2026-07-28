#pragma once
#include "Tile.h"

constexpr int size{4};

class Board{
private:
    Tile m_grid[size][size] {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,0}};
public:
    Board() = default;
    
    friend std::ostream& operator<<(std::ostream& out, const Board& board);
};