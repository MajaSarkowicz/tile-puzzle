#pragma once
#include <ostream>

class Tile{
private:
    int m_value{};
public:
    Tile() = default;
    Tile(int value): m_value{value}{}; // made non-explicit to handle implicit type conversion in Board.cpp
    bool isEmpty(){ return !m_value; };
    int getNum () const { return m_value; };
};

std::ostream& operator<<(std::ostream& out, const Tile& tile);