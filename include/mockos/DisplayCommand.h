#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "BasicDisplayVisitor.h"

enum DisplayCommandEnums{
    DisplayCommandSuccess = 0,
    DisplayCommandError = 1
};
//Displays the file to the output stream
class DisplayCommand: public AbstractCommand{
private:
    AbstractFileSystem * afs;//member variable for file system
public:
    DisplayCommand(AbstractFileSystem *);//creates the command with a file system
    int execute(std::string) override;//runs display command
    void displayInfo() override;//help message for DisplayCommand
};