#pragma once

#include "AbstractFile.h"
class ImageFile : public AbstractFile{
public:
    ImageFile(std::string filename);
    uint getSize() override;
    std::string getName() override;
    int write(std::vector<char>) override;
    int append(std::vector<char> c) override;
    void read() override;
protected:
    std::string name;
    std::vector<char> contents;
    char fileSize;
};

