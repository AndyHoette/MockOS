#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "MetadataDisplayVisitor.h"
#include <iomanip>
#include <iostream>
#include <set>
#include <string>

class LSCommand : AbstractCommand{
private:
    AbstractFileFactory * aff;
    AbstractFileSystem * afs;
public:
    LSCommand(AbstractFileSystem * afs, AbstractFileFactory * aff);
    int execute(std::string) override;
};