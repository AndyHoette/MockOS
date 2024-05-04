#include "mockos/RenameParsingStrategy.h"

using namespace std;

vector<string> RenameParsingStrategy::parse(string arg) {
    string existingFile = arg.substr(0,arg.find(' '));
    vector<string> args;
    args.push_back(arg);
    args.push_back(existingFile);
    return args;
}
