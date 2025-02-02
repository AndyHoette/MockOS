#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "AbstractFileVisitor.h"
typedef unsigned int uint;
enum returnValues{
    AbstractFileSuccess = 0,
    operationNotSupported = 1,
    wrongContents = 2,
    noContents = 3
};
class AbstractFile{
public:
    virtual std::vector<char> read() = 0;
    virtual int write(std::vector<char>) = 0; //returns a value indicating whether it worked
    virtual int append(std::vector<char>) = 0; //returns a value indicating whether it worked
    virtual uint getSize() = 0; //returns size of content array
    virtual std::string getName() = 0; //return name of file
    virtual ~AbstractFile() = default;//destructor
    virtual void accept(AbstractFileVisitor* vis) = 0;//allows a file to be visited by a visator
    virtual AbstractFile * clone(std::string newName) = 0;//clones a file
    virtual bool hasPermissions(){//gives permissions to a file for readOnly method
        return false;
    };
    virtual void changePermissions(){};//changes the permission bool
};