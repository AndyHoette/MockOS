#pragma once
#include "AbstractFile.h"
#include <string>

enum passwordProxyEnums{
    noPassword = 11
};
class PasswordProxy: public AbstractFile{
private:
    AbstractFile * protectedFile;
    std::string password;
public:
    PasswordProxy(AbstractFile * f, std::string& pw);
    ~PasswordProxy();
    std::vector<char> read() override;
    int write(std::vector<char>) override;
    int append(std::vector<char>) override;
    uint getSize() override;
    std::string getName() override;
    void accept(AbstractFileVisitor *vis) override;
protected:
    std::string passwordPrompt();
    bool passwordMatch(std::string guess);
};