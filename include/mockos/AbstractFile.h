#pragma once
#include <vector>
#include <string>
#include <iostream>
typedef unsigned int uint;
enum returnValues{
    AbstractFileSuccess = 0,
    operationNotSupported = 1,
    wrongContents = 2
};
class AbstractFile{
public:
    virtual void read() = 0;
    virtual int write(std::vector<char>) = 0;
    virtual int append(std::vector<char>) = 0;
    virtual uint getSize() = 0;
    virtual std::string getName() = 0;
    virtual ~AbstractFile() = default;
};