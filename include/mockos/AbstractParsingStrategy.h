#pragma once
#include <vector>
#include <string>
//Parsing strategy to tell the macro command how to run the different arguments
class AbstractParsingStrategy{
public:
    virtual std::vector<std::string> parse(std::string) = 0;//creates a vector of strings for the macrocommand to run on
    virtual ~AbstractParsingStrategy() = default;
};