#pragma once
#include "Direction.h"

namespace UserInput{
    bool isValidCommand(char ch);
    void ignoreLine();
    char getCharacter();
    char getCommandFromUser();
    Direction inputConversion(const char& rawInput);
    //void App();
    void App_Step5();
    std::string directionConversion(const Direction& direction);
};