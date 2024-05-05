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
    cantDeleteOpenFile = 5
};
class SimpleFileSystem: public AbstractFileSystem{
protected:
    std::map<std::string, AbstractFile*> allFiles; //how we store files
    std::set<AbstractFile*> openFiles; //a set of open files
public:
    int addFile(std::string, AbstractFile *) override; //checks that file name unique and that * != null
    int createFile(std::string) override; //if its txt or img adds it to map otherwise returns error
    int closeFile(AbstractFile *) override; //removes file from set if opened otherwise returns error
    int deleteFile(std::string) override; //delete file if not opened and exitsts
    AbstractFile * openFile(std::string) override;//adds file to set if its a file in map and not in set
    ~SimpleFileSystem();
    std::set<std::string> getFileNames() override;//gets the name of the file
};
