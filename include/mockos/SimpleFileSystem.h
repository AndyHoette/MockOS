#pragma once
#include "AbstractFileSystem.h"
#include <string>
#include <map>
#include <set>
enum SimpleFileReturns{
    SimpleFileSuccess = 0,
    fileExists = 1,
    noFile = 2,
    noViableFile = 3,
    noExt = 4,
};
class SimpleFileSystem: public AbstractFileSystem{
protected:
    std::map<std::string, AbstractFile*> allFiles;
    std::set<AbstractFile*> openFiles;
public:
    int addFile(std::string, AbstractFile *) override;
    int createFile(std::string) override;
    int closeFile(AbstractFile *) override;
    int deleteFile(std::string) override;
    AbstractFile * openFile(std::string) override;
};
