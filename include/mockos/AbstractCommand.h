#pragma once
#include <string>

enum AbstractCommandEnums{
    commandSuccess = 0
};

class AbstractCommand{
public:
    virtual int execute(std::string) = 0;
    virtual void displayInfo() = 0;
    virtual ~AbstractCommand() = default;
};