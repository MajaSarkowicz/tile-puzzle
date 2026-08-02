#include "Direction.h"

Direction Direction::operator-() const{
    switch (m_direction)
    {
    case Type::up:
        return Direction::down;
    case Type::down:
        return Direction::up;
    case Type::left:
        return Direction::right;
    case Type::right:
        return Direction::left;
    default:
        return Direction::up;
    }
}

std::ostream& operator<<(std::ostream& out, const Direction& direction){
    out << direction.m_direction;

    return out;
}
