#pragma once
#include "AbstractFile.h"
enum returnValue{
    success = 0
};
class TextFile: public AbstractFile{
private:
    std::vector<char> contents;
    std::string name;
public:
    TextFile(const std::string& filename);
    TextFile(std::string& n);
    void read() override;
    int write(std::vector<char>) override;
    int append(std::vector<char>) override;
    uint getSize() override;
    std::string getName() override;
};