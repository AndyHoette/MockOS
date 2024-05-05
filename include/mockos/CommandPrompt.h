#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include <map>
#include <sstream>
//error messages for the command prompt
enum CommandPromptEnums{
    insertionSuccess = 0,
    insertionFailure = 1,
    quit = 100,
};

class CommandPrompt{
private:
    std::map<std::string, AbstractCommand*> commandList;//list of commands mapped to their command input
    AbstractFileSystem * fileSystem;//member file system
    AbstractFileFactory * fileFactory;//member file factory
public:
    CommandPrompt();
    void setFileSystem(AbstractFileSystem *); //command prompt isn't initialized with a fileSystem so we have setters
    void setFileFactory(AbstractFileFactory *); //^^
    int addCommand(std::string, AbstractCommand*); //if we want a command to exists we use the addCommand function
    int run(); //this constantly prompts the user until a quit value is returned
    ~CommandPrompt();
protected:
    void listCommands(); //prints out the commands
    std::string prompt(); //prompts the user with a "$    "
};