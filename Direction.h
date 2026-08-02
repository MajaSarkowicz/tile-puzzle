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