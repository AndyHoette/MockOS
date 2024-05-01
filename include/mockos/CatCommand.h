#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "BasicDisplayVisitor.h"
#include <set>
#include <string>

enum CatCommandEnums{
    CatCommandError = 1,
    noSave = 2,
    CatCommandSuccess = 0
};

class CatCommand: public AbstractCommand{
private:
    AbstractFileSystem * afs;
public:
    CatCommand(AbstractFileSystem*);
    int execute(std::string) override;
    void displayInfo() override;
};