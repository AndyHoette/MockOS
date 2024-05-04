#include "mockos/CatParsingStrategy.h"
using namespace std;

vector<string> CatParsingStrategy::parse(string arg) {
    string existingFile = arg.substr(0,arg.find(' '));
    vector<string> args;
    if(arg.find("-a") !=string::npos){
        string cat = existingFile + " -a";
        args.push_back(cat);
    }
    else{
        args.push_back(existingFile);
    }
    if(arg.find("-d") !=string::npos)
    {
        string disp = existingFile + " -d";
        args.push_back(disp);
    }
    else {
        args.push_back(existingFile);
    }
    return args;
}