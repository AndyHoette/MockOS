#include "mockos/CatParsingStrategy.h"
using namespace std;
//This is the parsing strategy for the cat and display macroCommand
vector<string> CatParsingStrategy::parse(string arg) {
    string existingFile = arg.substr(0,arg.find(' '));//finds the first space for the file
    vector<string> args;//creates the args vector
    if(arg.find("-a") !=string::npos){
        string cat = existingFile + " -a";//if -a is found it's added to the vector
        args.push_back(cat);
    }
    else{
        args.push_back(existingFile);
    }
    if(arg.find("-d") !=string::npos)//if -d is found its added to the vector
    {
        string disp = existingFile + " -d";
        args.push_back(disp);
    }
    else {
        args.push_back(existingFile);
    }
    return args;//returs the vector of arguments
}