#pragma once

#include "AbstractFile.h"
//Creates files
class AbstractFileFactory{
public:
    virtual AbstractFile* createFile(std::string) = 0;
    virtual ~AbstractFileFactory() = default;
};