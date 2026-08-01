#include "UserInput.h"
#include "Board.h"
#include <iostream>
#include <limits>

namespace UserInput
{
    void ignoreLine()
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    void App(){
        Board board{};
        std::cout << board << std::endl;
        userInputLoop();
    }

    void userInputLoop(){
        while(true){
            char motionCommand{}; 
            std::cin >> motionCommand;
            ignoreLine(); //when a string is passed, if it starts with a correct value, it will be registered as a valid motion command
            switch (motionCommand)
            {
            case 'w':
                std::cout << "Valid command: " << motionCommand << std::endl;
                break;
            
            case 's':
                std::cout << "Valid command: " << motionCommand << std::endl;
                break;
            
            case 'a':
                std::cout << "Valid command: " << motionCommand << std::endl;
                break;
           
            case 'd':
                std::cout << "Valid command: " << motionCommand << std::endl;
                break;

            case 'q':
                std::cout << "Valid command: " << motionCommand << std::endl;
                std::cout << "\n\nBye!\n\n";
                return;
                
            default:
                break;
            }
        }
    }
}
