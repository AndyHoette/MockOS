#pragma once
#include <string>
#include <set>
#include "AbstractFile.h"

enum AbstractFileSystemEnums{
    fileSuccess = 0
};

class AbstractFileSystem{
public:
    virtual std::set<std::string> getFileNames() = 0;
    virtual int addFile(std::string, AbstractFile*) = 0;
    virtual int createFile(std::string) = 0;
    virtual int deleteFile(std::string) = 0;
    virtual AbstractFile* openFile(std::string) = 0;
    virtual int closeFile(AbstractFile*) = 0;
    virtual std::set<AbstractFile*> getFiles() = 0;
    virtual ~AbstractFileSystem() = default;
};