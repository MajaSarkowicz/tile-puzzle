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
    static int random(){
        return Random::get(static_cast<int>(Type::up), static_cast<int>(Type::right));
    }
};