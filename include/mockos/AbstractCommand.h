#pragma once
#include <string>

enum AbstractCommandEnums{
    commandSuccess = 0
};
//This is the template for every command that is added later on
class AbstractCommand{
public:
    virtual int execute(std::string) = 0;//runs the command
    virtual void displayInfo() = 0;//infomration on how to run a command
    virtual ~AbstractCommand() = default;//destructor
};