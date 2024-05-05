#pragma once
#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"
#include <string>

enum RemoveCommandEnums{
    successful = 0,
    failure = 1
};
//removes a file from a file system
class RemoveCommand: public AbstractCommand{
private:
    AbstractFileSystem* afs;//file system
public:
    RemoveCommand(AbstractFileSystem*);//creates the remove command with the file system
    int execute(std::string) override; //returns a 0 or 1 saying whether a file was deleted
    void displayInfo() override;//displays the help message for remove command
};