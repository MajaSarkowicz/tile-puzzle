#include "Board.h"

constexpr int g_consoleLines{ 25 };
constexpr int size{ 4 };

std::ostream& operator<<(std::ostream& out, Board board){
    for(int i{}; i < g_consoleLines; ++i){
        out << std::endl;
    }
    for(int i{}; i < size; ++i){
        for(int j{}; j < size; ++j){
            out << board.m_tiles[i][j];
        }
        out << std::endl;
    }
    
    return out;
}

Point Board::getEmptyTileCoords(){
    for (int i{0}; i < s_size; ++i)
    {
        for (int j{0}; j < s_size; ++j)
        {
            if(m_tiles[j][i].isEmpty()) // Cartesian logic is opposite to matrix logic, movement on the x-axis is an iteration through the columns
                return Point{i,j};
        }
    } 
}

void Board::swapTiles(Point p1, Point p2){ 
    Tile temp{};
    temp = m_tiles[p1.y][p1.x];
    m_tiles[p1.y][p1.x] = m_tiles[p2.y][p2.x];
    m_tiles[p2.y][p2.x] = temp;
}

void Board::moveTile(Direction dir){
    Point emptyTile{getEmptyTileCoords()};
    Point adjecent{emptyTile.getAdjacentPoint(-dir)}; 
    
    if(isValid(emptyTile) && isValid(adjecent)) 
        swapTiles(adjecent, emptyTile);
}
