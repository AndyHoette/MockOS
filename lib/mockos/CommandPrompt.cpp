#include "mockos/CommandPrompt.h"
#include <utility>


using namespace std;

CommandPrompt::CommandPrompt(): fileFactory(nullptr),fileSystem(nullptr) {}

void CommandPrompt::setFileSystem(AbstractFileSystem * newFS) {
    fileSystem = newFS;
}

void CommandPrompt::setFileFactory(AbstractFileFactory * newFF) {
    fileFactory = newFF;
}

int CommandPrompt::addCommand(string newName, AbstractCommand * newCommand) {
    pair<string, AbstractCommand*> newPair;
    newPair.first = newName;
    newPair.second = newCommand;
    if(commandList.insert(newPair).second){
        return insertionSuccess;
    }
    return insertionFailure;
}

void CommandPrompt::listCommands() {
    for(auto it = commandList.begin(); it!= commandList.end(); ++it){
       cout << it->first << endl;
    }
}

string CommandPrompt::prompt() {
    cout << "Enter A valid command, ";
    cout << "q to quit, ";
    cout << "help for list of command, ";
    cout << "or help followed by a command name for more information about that command" << endl;
    cout << "$   ";
    string input;
    getline(cin, input);
    return input;
}

int CommandPrompt::run() {
    string userInput;
    while(1){ //why tf it in a while loop
        userInput = prompt();
        if(userInput == "q"){
            return quit;
        }
        if(userInput == "help"){
            listCommands();
            continue;
        }
        if(userInput.find(" ")==string::npos){
            auto cmnd = commandList.find(userInput);
            if(cmnd == commandList.end()){
                cout << "Command is not Found" << endl;
                continue;
            }
            if(cmnd->second->execute("")!=commandSuccess){
                cout << "Command Error" << endl;
                continue;
            }
        }
        istringstream ss(userInput);
        string FirstWord;
        string secondWord;
        ss >> FirstWord;
        if(FirstWord=="help"){
            ss >> secondWord;
            auto cmnd = commandList.find(secondWord);
            if(cmnd == commandList.end()){
                cout << "Command is not Found" << endl;
                continue;
            }
            cmnd->second->displayInfo();
            continue;
        }
        secondWord = ss.str();
        auto cmnd = commandList.find(FirstWord);
        if(cmnd == commandList.end()){
            cout << "Command is not Found 123" << endl;
            continue;
        }
        cmnd->second->execute(secondWord);
    }
}




