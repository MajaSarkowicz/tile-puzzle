#pragma once
#include "Tile.h"

constexpr int s_size{4};

class Board{
private:
    Tile m_tiles[s_size][s_size]{ // said tidieous explicit initialization
        Tile{ 1 }, Tile { 2 }, Tile { 3 } , Tile { 4 },
        Tile { 5 } , Tile { 6 }, Tile { 7 }, Tile { 8 },
        Tile { 9 }, Tile { 10 }, Tile { 11 }, Tile { 12 },
        Tile { 13 }, Tile { 14 }, Tile { 15 }, Tile { 0 } };
public:
    Board() = default;
    
    friend std::ostream& operator<<(std::ostream& out, const Board& board);
};