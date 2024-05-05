#include "mockos/RenameParsingStrategy.h"

using namespace std;

vector<string> RenameParsingStrategy::parse(string arg) {
    string existingFile = arg.substr(0,arg.find(' '));
    vector<string> args;
    args.push_back(arg); //copy needs two files
    args.push_back(existingFile); //but remove only needs one
    return args;
}
