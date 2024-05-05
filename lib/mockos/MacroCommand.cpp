#include "mockos/MacroCommand.h"

using namespace std;

void MacroCommand::addCommand(AbstractCommand * newCommand) { //if we get a newCommand just add it to the vector
    commands.push_back(newCommand);
}

void MacroCommand::setParseStrategy(AbstractParsingStrategy * newParser) {
    parser = newParser; //basic setter
}

void MacroCommand::displayInfo() { //when help is run on this just print out the individual commands help message
    for(auto it = commands.begin(); it!= commands.end();it++){
        (*it)->displayInfo();
    }
}

int MacroCommand::execute(std::string arg) {
    vector<string> listOfArgs = parser->parse(arg); //the parser gives us a vector of args
    AbstractCommand * commandToRun;
    for(int i = 0; i<commands.size(); i++){ //loop through the command and pass the corresponding arg
        commandToRun = commands[i];
        int executeValue = commandToRun->execute(listOfArgs[i]);
        if(executeValue!=commandSuccess){
            return MacroCommandError;
        }
    }
    return MacroCommandSuccess;
}

MacroCommand::MacroCommand(AbstractFileSystem * newAFS): afs(newAFS){} //basic constructor

MacroCommand::~MacroCommand(){ //when we delete a macro we need to delete the commands it holds and the parser
    for(auto it = commands.begin();it!= commands.end();it++){
        delete *it;
    }
    delete parser;
}