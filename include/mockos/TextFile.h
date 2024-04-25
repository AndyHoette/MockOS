#pragma once
#include "AbstractFile.h"
enum returnValue{
    success = 0
};
class TextFile: public AbstractFile{
private:
    std::vector<char> contents; //whats written in the file
    std::string name; //name of file
public:
    TextFile(const std::string& filename); //creates a txt file with the given name
    void read() override; //print out the contents
    int write(std::vector<char>) override; //makes contents equal to the passed string
    int append(std::vector<char>) override; //add this to the extisting contents
    uint getSize() override; //returns how many chars in contents
    std::string getName() override; //returns name
};