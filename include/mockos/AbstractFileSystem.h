#pragma once
#include <string>
#include <set>
#include "AbstractFile.h"

enum AbstractFileSystemEnums{
    fileSuccess = 0
};

class AbstractFileSystem{
public:
    virtual std::set<std::string> getFileNames() = 0;//gets the names
    virtual int addFile(std::string, AbstractFile*) = 0;//adds a file to a file system
    virtual int createFile(std::string) = 0;//creates a file
    virtual int deleteFile(std::string) = 0;//deletes a file
    virtual AbstractFile* openFile(std::string) = 0;//opens a file
    virtual int closeFile(AbstractFile*) = 0;//closes a file
    virtual ~AbstractFileSystem() = default;//destructor
};