#pragma once

#include "AbstractFile.h"
class ImageFile : public AbstractFile{
public:
    ImageFile(std::string filename); //creates a blank img file with a given name
    uint getSize() override; //returns the size of file
    std::string getName() override; //returns name
    int write(std::vector<char>) override; //makes the passed array = contents if size works
    int append(std::vector<char> c) override; //always return a 1
    void read() override; //prints out in tic tac toe fashion
protected:
    std::string name; // name of the file
    std::vector<char> contents; //Vector of contents
    char fileSize; //The file size is a char
};

