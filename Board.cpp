#include "Tile.h"
#include "Board.h"

constexpr int g_consoleLines{ 25 };
constexpr int size{ 4 };

std::ostream& operator<<(std::ostream& out, const Board& board){
    for(int i{}; i < g_consoleLines; ++i){
        out << std::endl;
    }
    for(int i{}; i < size; ++i){
        for(int j{}; j < size; ++j){
            out << board.m_grid[i][j];
        }
        out << std::endl;
    }
    return out;
}