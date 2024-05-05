#pragma once
#include "AbstractParsingStrategy.h"

class CatParsingStrategy : public AbstractParsingStrategy{
public:
    std::vector<std::string> parse(std::string) override;//Parsing strategy for cat and display macro command
};
