#pragma once

#include "AbstractCommand.h"
#include "AbstractParsingStrategy.h"
#include <vector>
#include <iostream>

class MacroCommand : public AbstractCommand{
private:
    std::vector<AbstractCommand*> commands;
    AbstractParsingStrategy* parser;
public:
    int execute(std::string) override;
    void displayInfo() override;
    void addCommand(AbstractCommand *);
    void setParseStrategy(AbstractParsingStrategy *);
};