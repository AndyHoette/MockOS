#pragma once
#include "AbstractFileFactory.h"
#include "ImageFile.h"
#include "TextFile.h"
class SimpleFileFactory:public AbstractFileFactory{
public:
    AbstractFile * createFile(std::string) override; //returns a new file if string ends in .txt or .img
};