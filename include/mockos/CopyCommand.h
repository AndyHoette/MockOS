#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
//copy command error messages
enum CopyCommandEnums{
    CopyCommandError = 1,
    CopyCommandSuccess = 0
};
//copies a file with this command
class CopyCommand: public AbstractCommand{
private:
    AbstractFileSystem * afs;//file system
public:
    CopyCommand(AbstractFileSystem*);//constructor that takes in a file system
    int execute(std::string) override;//executes the copy command
    void displayInfo() override;//displays info when help called
};