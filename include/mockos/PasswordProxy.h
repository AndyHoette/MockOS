#pragma once
#include "AbstractFile.h"
#include <string>

enum passwordProxyEnums{
    noPassword = 11
};
//Creates a proxy file that only allows you to access the actual file with the correct passwrod
class PasswordProxy: public AbstractFile{
private:
    AbstractFile * protectedFile; //password proxy holds file under lock and key
    std::string password;
public:
    PasswordProxy(AbstractFile * f, std::string& pw); //pp require a file and password at construction
    ~PasswordProxy();
    std::vector<char> read() override;//reads the file
    int write(std::vector<char>) override;//writes the file
    bool hasPermissions() override;//changes the permission of a file
    int append(std::vector<char>) override; //all the override methods that need to be protected work iff the password
                                            //is given correctly
    uint getSize() override;
    std::string getName() override; //getSize and getName don't need a password to Access
    void accept(AbstractFileVisitor *vis) override;//accepts the visitor
    AbstractFile * clone(std::string newName) override;//clones a file
protected:
    std::string passwordPrompt();//since these methods are required for how the class works but the user doesn't
    bool passwordMatch(std::string guess); //need them, they are protect to declutter the interface
};