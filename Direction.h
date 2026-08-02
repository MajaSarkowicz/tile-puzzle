#pragma once
#include "Random.h"
#include <ostream>

class Direction{
public:
    enum Type{
        up,
        down,
        left,
        right,
        maxDirections,
    };
private:
    Type m_direction{};
public:
    Direction() = default;
    Direction(Type direction) : m_direction{direction}{}
    Type getType() const { return m_direction; }
    Direction operator-() const;
    friend std::ostream& operator<<(std::ostream& out, const Direction& direction);
    static Direction random(){
        Type random{ static_cast<Type>(Random::get(0, Type::maxDirections - 1)) };
        return Direction{ random };
    }
};

struct Point{
    int x{};
    int y{};

    friend bool operator==(const Point& p1, const Point& p2)
    {
        return (p1.x == p2.x && p1.y == p2.y);
    }
    
    friend bool operator!=(const Point& p1, const Point& p2)
    {
        return !(operator==(p1, p2));
    }

    const Point& getAdjacentPoint(Direction dir) {
        switch (dir.getType())
        {
        case Direction::up:     return Point{ x,     y - 1 };
        case Direction::down:   return Point{ x,     y + 1 };
        case Direction::left:   return Point{ x - 1, y };
        case Direction::right:  return Point{ x + 1, y };
        default:                break;
        }
    }
};