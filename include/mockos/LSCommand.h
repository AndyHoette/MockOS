#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "MetadataDisplayVisitor.h"
#include <iomanip>
#include <iostream>
#include <set>
#include <string>

class LSCommand : public AbstractCommand{
private:
    AbstractFileSystem * afs;
public:
    LSCommand(AbstractFileSystem * afs);
    int execute(std::string) override;
    void displayInfo() override;
};