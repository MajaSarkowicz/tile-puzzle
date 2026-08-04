#include "UserInput.h"
#include "Board.h"
#include "Direction.h"
#include "Tile.h"
#include <iostream>
#include <limits>

namespace UserInput
{
    bool isValidCommand(char ch)
    {
        return ch == 'w'
            || ch == 'a'
            || ch == 's'
            || ch == 'd'
            || ch == 'q';
    }

    void ignoreLine()
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    char getCharacter()
    {
        char operation{};
        std::cin >> operation;
        ignoreLine(); // remove any extraneous input
        return operation;
    }

    char getCommandFromUser()
    {
        char ch{};
        while (!isValidCommand(ch))
            ch = getCharacter();

        return ch;
    }

    Direction inputConversion(char rawInput){
        switch (rawInput)
        {
        case 'w':
            return Direction::up;
        case 's':
            return Direction::down;
        case 'a':
            return Direction::left;
        case 'd':
            return Direction::right;
        }
    }

    std::string directionConversion(const Direction& direction){
        switch (direction.getType())
        {
        case Direction::up:
            return "up";
        case Direction::down:
            return "down";
        case Direction::left:
            return "left";
        case Direction::right:
            return "right";
        default:
            return "unknown";
        }
    }

    void printRandomDir(){
        std::cout << "Generating random direction... " << Direction::random() << std::endl;
    }

    void App_Step5(){
        Board board{};
        std::cout << board;

        for(int i{}; i<4; ++i) printRandomDir();

        std::cout << "Enter direction: ";

        while (true)
        {
            char ch{ UserInput::getCommandFromUser() };

            if (ch == 'q')
            {
                std::cout << "\n\nBye!\n\n";
                return;
            }

        Direction dir{UserInput::inputConversion(ch)};
        std::cout << "You entered direction: " << dir << '\n'; 
        board.moveTile(dir); //to jest kurwa krzywe
        std::cout << board; 
        }
    }
};
