#pragma once
#include "AbstractFile.h"
#include <string>

enum passwordProxyEnums{
    noPassword = 11
};
class PasswordProxy: public AbstractFile{
private:
    AbstractFile * protectedFile; //password proxy holds file under lock and key
    std::string password;
public:
    PasswordProxy(AbstractFile * f, std::string& pw); //pp require a file and password at construction
    ~PasswordProxy();
    std::vector<char> read() override;
    int write(std::vector<char>) override;
    bool hasPermissions() override;
    int append(std::vector<char>) override; //all the override methods that need to be protected work iff the password
                                            //is given correctly
    uint getSize() override;
    std::string getName() override; //getSize and getName don't need a password to Access
    void accept(AbstractFileVisitor *vis) override;
    AbstractFile * clone(std::string newName) override;
protected:
    std::string passwordPrompt();//since these methods are required for how the class works but the user doesn't
    bool passwordMatch(std::string guess); //need them, they are protect to declutter the interface
};