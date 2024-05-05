#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "BasicDisplayVisitor.h"
#include <set>
#include <string>
//different error messages
enum CatCommandEnums{
    CatCommandError = 1,
    noSave = 2,
    CatCommandSuccess = 0
};
//Cat command allows the user to write to a file
class CatCommand: public AbstractCommand{
private:
    AbstractFileSystem * afs;
public:
    CatCommand(AbstractFileSystem*);//creates the catCommand with a file system
    int execute(std::string) override;//writes to the file
    void displayInfo() override;//display info for the file
};