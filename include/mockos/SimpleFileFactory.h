#pragma once
#include "AbstractFileFactory.h"
#include "mockos/ImageFile.h"
#include "mockos/TextFile.h"
class SimpleFileFactory:public AbstractFileFactory{
public:
    AbstractFile * createFile(std::string) override;
};