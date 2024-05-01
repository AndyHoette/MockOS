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

class MacroCommand : public AbstractCommand{
private:
    std::vector<AbstractCommand*> commands;
    AbstractParsingStrategy* parser;
    AbstractFileSystem * afs;
public:
    MacroCommand(AbstractFileSystem*);
    int execute(std::string) override;
    void displayInfo() override;
    void addCommand(AbstractCommand *);
    void setParseStrategy(AbstractParsingStrategy *);
};