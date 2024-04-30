#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include <map>
#include <sstream>

enum CommandPromptEnums{
    insertionSuccess = 0,
    insertionFailure = 1,
    quit = 100,
    commandError = 2,
    noCommand = 3
};

class CommandPrompt{
private:
    std::map<std::string, AbstractCommand*> commandList;
    AbstractFileSystem * fileSystem;
    AbstractFileFactory * fileFactory;
public:
    CommandPrompt();
    void setFileSystem(AbstractFileSystem *);
    void setFileFactory(AbstractFileFactory *);
    int addCommand(std::string, AbstractCommand*);
    int run();
protected:
    void listCommands();
    std::string prompt();
};