#include "Tile.h"

std::ostream& operator<<(std::ostream& out, const Tile& tile){
    if(tile.getNum() < 10 && tile.getNum())
        out << "  " << tile.getNum() << "  ";
    else if(tile.getNum() >= 9){
        out << " " << tile.getNum() << "  ";
    }
    else
        out << " " << " " << "  ";
    
    return out;
};

bool operator== (Tile t1, Tile t2){
    return (t1.m_value == t2.m_value);
}