#pragma once
#include "Tile.h"
#include "Direction.h"

constexpr int s_size{4};

class Board{
private:
    Tile m_tiles[s_size][s_size]{
        Tile{ 1 }, Tile { 2 }, Tile { 3 } , Tile { 4 },
        Tile { 5 } , Tile { 6 }, Tile { 7 }, Tile { 8 },
        Tile { 9 }, Tile { 10 }, Tile { 11 }, Tile { 12 },
        Tile { 13 }, Tile { 14 }, Tile { 15 }, Tile { 0 } };
public:
    Board() = default;
    
    friend std::ostream& operator<<(std::ostream& out, Board board);
    friend bool operator==(Board b1, Board b2);
    
    bool isValid(const Point& point){
        return (point.x < s_size && point.x >= 0 && point.y < s_size && point.y >= 0);
    }

    Point getEmptyTileCoords();

    void swapTiles(Point p1, Point p2);

    void moveTile(Direction dir);

    Board randomize();

    bool playerWon();
};