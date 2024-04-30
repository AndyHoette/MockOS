#pragma once
#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"
#include <string>

enum RemoveCommandEnums{
    successful = 0,
    failure = 1
};

class RemoveCommand: public AbstractCommand{
private:
    AbstractFileFactory* aff;
    AbstractFileSystem* afs;
public:
    RemoveCommand(AbstractFileSystem*, AbstractFileFactory*);
    int execute(std::string) override; //returns a 0 or 1 saying whether a file was deleted
};