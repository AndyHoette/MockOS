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
    std::vector<char> read() override;
    int write(std::vector<char>) override;
    int append(std::vector<char>) override; //all the override methods that need to be protected work iff the password
    //is given correctly
    uint getSize() override;
    std::string getName() override; //getSize and getName don't need a password to Access
    void accept(AbstractFileVisitor *vis) override;
    AbstractFile * clone(std::string newName) override;
    bool hasPermissions() override;
    void changePermissions() override;
};