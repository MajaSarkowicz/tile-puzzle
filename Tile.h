#pragma once
#include <iostream>

class Tile{
private:
    int m_value{};
public:
    Tile() = default;
    friend bool operator== (Tile t1, Tile t2);
    explicit Tile(int value): m_value{value}{}; // back to explicit - tidieous Board initialization was expected
    bool isEmpty(){ return !m_value; };
    int getNum () const { return m_value; };
};

std::ostream& operator<<(std::ostream& out, const Tile& tile);