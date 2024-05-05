#pragma once
#include "AbstractParsingStrategy.h"
//parsing strategy for the rename macroCommand
class RenameParsingStrategy: public AbstractParsingStrategy{
public:
    std::vector<std::string> parse(std::string) override;
};