#pragma once
#include "Direction.h"

namespace UserInput{
    bool isValidCommand(char ch);
    void ignoreLine();
    char getCharacter();
    char getCommandFromUser();
    Direction inputConversion(char rawInput);
    void App();
};