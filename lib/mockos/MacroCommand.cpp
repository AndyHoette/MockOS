#include "mockos/MacroCommand.h"

using namespace std;

void MacroCommand::addCommand(AbstractCommand * newCommand) {
    commands.push_back(newCommand);
}

void MacroCommand::setParseStrategy(AbstractParsingStrategy * newParser) {
    parser = newParser;
}

void MacroCommand::displayInfo() {
    for(auto it = commands.begin(); it!= commands.end();it++){
        (*it)->displayInfo();
    }
}

int MacroCommand::execute(std::string arg) {
    vector<string> listOfArgs = parser->parse(arg);
    AbstractCommand * commandToRun;
    for(int i = 0; i<commands.size(); i++){
        commandToRun = commands[i];
        int executeValue = commandToRun->execute(listOfArgs[i]);
        if(executeValue!=commandSuccess){
            return MacroCommandError;
        }
    }
    return MacroCommandSuccess;
}

MacroCommand::MacroCommand(AbstractFileSystem * newAFS): afs(newAFS){}

MacroCommand::~MacroCommand(){
    for(auto it = commands.begin();it!= commands.end();it++){
        delete *it;
    }
    delete parser;
}