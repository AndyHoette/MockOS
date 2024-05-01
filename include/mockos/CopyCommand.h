#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

enum CopyCommandEnums{
    CopyCommandError = 1,
    CopyCommandSuccess = 0
};

class CopyCommand: public AbstractCommand{
private:
    AbstractFileSystem * afs;
public:
    CopyCommand(AbstractFileSystem*);
    int execute(std::string) override;
    void displayInfo() override;
};