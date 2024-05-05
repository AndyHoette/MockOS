#pragma once
#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"
#include "PasswordProxy.h"

enum TouchCommandEnums{
    TouchCreateError = 1,
    TouchAddError = 2
};
//command that creates the files
class TouchCommand: public AbstractCommand{
private:
    AbstractFileFactory * aff;
    AbstractFileSystem * afs;
public:
    TouchCommand(AbstractFileSystem *, AbstractFileFactory *); //touch command needs a fileSystem and FileFactory
    void displayInfo() override; //prints out how to run
    int execute(std::string) override; //returns a value inidcating whether a file was created successfully
};
