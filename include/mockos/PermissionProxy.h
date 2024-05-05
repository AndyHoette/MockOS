#pragma once
#include "AbstractFile.h"
#include <string>

class PermissionProxy: public AbstractFile{
private:
    AbstractFile * myFile; //password proxy holds file under lock and key
    bool readOnly;
public:
    PermissionProxy(AbstractFile * f);
    PermissionProxy(AbstractFile * f, bool& readOnly); //pp require a file and password at construction
    ~PermissionProxy();
    std::vector<char> read() override;//reads the file
    int write(std::vector<char>) override;//writes to the file
    int append(std::vector<char>) override; //all the override methods that need to be protected work iff the password
    //is given correctly
    uint getSize() override;//gets the size of the file
    std::string getName() override; //getSize and getName don't need a password to Access
    void accept(AbstractFileVisitor *vis) override;//allows the visitor to display the file
    AbstractFile * clone(std::string newName) override;//clones the file
    bool hasPermissions() override;//has permission proxy
    void changePermissions() override;//changes the permission
};