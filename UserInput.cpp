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

    void App(){
        Board board{};
        board.randomize();
        std::cout << board;

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
            board.moveTile(dir); 
            if(board.playerWon())
            {
                std::cout << "\n\nYou won!\n\n";
                return;
            }
            std::cout << board;
    }
}
};
