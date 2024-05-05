#pragma once

#include "AbstractCommand.h"
#include "AbstractParsingStrategy.h"
#include "AbstractFileSystem.h"
#include <vector>
#include <iostream>

enum MacroCommandEnums{
    MacroCommandSuccess = 0,
    MacroCommandError = 1
};
//MacroCommand is a command made up of multiple commands to make it easier to run things at once
class MacroCommand : public AbstractCommand{
private:
    std::vector<AbstractCommand*> commands;//Vector of commands
    AbstractParsingStrategy* parser;//Parser gives the list of commands in order
    AbstractFileSystem * afs;//file system
public:
    MacroCommand(AbstractFileSystem*);//creates a macrocommand
    int execute(std::string) override;//runs the command
    void displayInfo() override;//display info for the specific commands
    void addCommand(AbstractCommand *);//add a command to the vector
    void setParseStrategy(AbstractParsingStrategy *);//se the parsing strategy
    ~MacroCommand() override;//Destructor
};