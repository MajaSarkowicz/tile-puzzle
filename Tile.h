#pragma once
#include <ostream>

class Tile{
private:
    int m_value{};
public:
    Tile() = default;
    explicit Tile(int value): m_value{value}{}; // back to explicit - tidieous Board initialization was expected
    bool isEmpty(){ return !m_value; };
    int getNum () const { return m_value; };
};

std::ostream& operator<<(std::ostream& out, const Tile& tile);