#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "MetadataDisplayVisitor.h"
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
//LS command lists the files in the file system
class LSCommand : public AbstractCommand{
private:
    AbstractFileSystem * afs;
public:
    LSCommand(AbstractFileSystem * afs);//Constructor takes in a file system
    int execute(std::string) override;//runs the LS command
    void displayInfo() override;//Information for when help is called on ls
};