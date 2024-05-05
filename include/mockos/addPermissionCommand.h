#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "BasicDisplayVisitor.h"
#include "PermissionProxy.h"
#include <set>
#include <string>

enum addPermissionCommandEnums{
    fail = 100
};
//Adds a permisson proxy or toggles the permission
class addPermissionCommand : public AbstractCommand{
private:
    AbstractFileSystem * afs;//member variable for the abstract file system
public:
    addPermissionCommand(AbstractFileSystem *);//adds the permission command
    int execute(std::string) override;//executes the command on the passed file
    void displayInfo() override;//displays the information on how to run the permission command
};
