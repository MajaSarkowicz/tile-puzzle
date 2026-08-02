#include "UserInput.h"
#include "Board.h"
#include "Direction.h"
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

    Direction inputConversion(const char& rawInput){
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

    // void App(){
    //     Board board{};
    //     std::cout << board;

    //     while (true)
    //     {
    //         char ch{ UserInput::getCommandFromUser() };
    //         std::cout << "You entered direction: " << ch << '\n';

    //         if (ch == 'q')
    //         {
    //             std::cout << "\n\nBye!\n\n";
    //             return;
    //         }
    //     }
    // }

    void printRandomDir(){
        std::cout << "Generating random direction... " << directionConversion(static_cast<Direction::Type>(Direction::random())) << std::endl;
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

            std::cout << "You entered direction: " << directionConversion(inputConversion(ch)) << '\n'; 
        }
    }
};
