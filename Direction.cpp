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

std::ostream& operator<<(std::ostream& stream, Direction dir){
        switch (dir.getType())
    {
    case Direction::up:     return (stream << "up");
    case Direction::down:   return (stream << "down");
    case Direction::left:   return (stream << "left");
    case Direction::right:  return (stream << "right");
    default:                break;
    }
}

Point Point::getAdjacentPoint(Direction dir){
    switch (dir.getType())
    {
    case Direction::up:     return Point{ x,     y - 1 };
    case Direction::down:   return Point{ x,     y + 1 };
    case Direction::left:   return Point{ x - 1, y };
    case Direction::right:  return Point{ x + 1, y };
    default:                break;
    }
}
