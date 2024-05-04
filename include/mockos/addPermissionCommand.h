#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "BasicDisplayVisitor.h"
#include "PermissionProxy.h"
#include <set>
#include <string>

enum addPermissionCommandEnums{
    failure = 100
};

class addPermissionCommand: public AbstractCommand{
private:
    AbstractFileSystem * afs;
public:
    addPermissionCommand(AbstractFileSystem *);
    int execute(std::string) override;
    void displayInfo() override;
};
