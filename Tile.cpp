#include "Tile.h"

std::ostream& operator<<(std::ostream& out, const Tile& tile){
    if(tile.getNum())
        out << " " << tile.getNum() << "  ";
    else
        out << " " << " " << "  ";
    
    return out;
};
