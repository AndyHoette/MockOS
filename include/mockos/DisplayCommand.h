#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "BasicDisplayVisitor.h"

enum DisplayCommandEnums{
    DisplayCommandSuccess = 0,
    DisplayCommandError = 1
};

class DisplayCommand: public AbstractCommand{
private:
    AbstractFileSystem * afs;
public:
    DisplayCommand(AbstractFileSystem *);
    int execute(std::string) override;
    void displayInfo() override;
};