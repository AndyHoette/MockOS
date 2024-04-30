#pragma once
#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"

enum TouchCommandEnums{
    TouchCreateError = 1,
    TouchAddError = 2
};

class TouchCommand: public AbstractCommand{
private:
    AbstractFileFactory * aff;
    AbstractFileSystem * afs;
public:
    TouchCommand(AbstractFileSystem *, AbstractFileFactory *);
    void displayInfo() override;
    int execute(std::string) override;
};
