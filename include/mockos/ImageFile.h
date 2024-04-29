#pragma once
#include "AbstractFile.h"
enum{
    FirstIndex = 0,
    SecondIndex = 1,
};
class ImageFile : public AbstractFile{
public:
    ImageFile(std::string filename); //creates a blank img file with a given name
    uint getSize() override; //returns the size of file
    std::string getName() override; //returns name
    int write(std::vector<char>) override; //makes the passed array = contents if size works
    int append(std::vector<char> c) override; //always return a 1
    std::vector <char> read() override; //returns a vector of contents
    void accept(AbstractFileVisitor* vis) override;
protected:
    std::string name; // name of the file
    std::vector<char> contents; //Vector of contents
    char fileSize; //The file size is a char
};

