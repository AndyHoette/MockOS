#include "mockos/CommandPrompt.h"
#include <utility>


using namespace std;
//sets the command prompt
CommandPrompt::CommandPrompt(): fileFactory(nullptr),fileSystem(nullptr) {}

void CommandPrompt::setFileSystem(AbstractFileSystem * newFS) {
    fileSystem = newFS;
}

void CommandPrompt::setFileFactory(AbstractFileFactory * newFF) {
    fileFactory = newFF;
}
//adding a command to the command prompt
int CommandPrompt::addCommand(string newName, AbstractCommand * newCommand) {
    pair<string, AbstractCommand*> newPair;
    newPair.first = newName;
    newPair.second = newCommand;
    if(commandList.insert(newPair).second){
        return insertionSuccess;
    }
    return insertionFailure;
}
//lists the commands
void CommandPrompt::listCommands() {
    for(auto it = commandList.begin(); it!= commandList.end(); ++it){
       cout << it->first << endl;
    }
}

string CommandPrompt::prompt() {
    cout << "Enter A valid command, ";//gives list of options
    cout << "q to quit, ";
    cout << "help for list of command, ";
    cout << "or help followed by a command name for more information about that command" << endl;
    cout << "$   ";
    flush(cout);
    string input;
    getline(cin, input);//gets the user input
    return input;
}
//runs the command prompt
int CommandPrompt::run() {
    string userInput;
    while(1){
        userInput = prompt();
        if(userInput == "q"){
            return quit;
        }
        if(userInput == "help"){
            listCommands();
            continue;
        }
        if(userInput.empty()){
            continue;
        }
        if(userInput.find(" ")==string::npos){//if command doesn't exist
            auto cmnd = commandList.find(userInput);
            if(cmnd == commandList.end()){
                cout<<"-----"<<endl;
                cout<<userInput<<endl;
                cout << "Command is not Found" << endl;
                continue;
            }
            if(cmnd->second->execute("")!=commandSuccess){
                cout << "Command Error" << endl;
                continue;
            }
        }//takes in the user input and separates into command and argument
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
        }//gets the command argument
        secondWord = ss.str();
        string swrod = secondWord.substr(secondWord.find(' ')+1);
        auto cmnd = commandList.find(FirstWord);
        if(cmnd == commandList.end()){
            cout << "Command is not Found" << endl;
            continue;
        }//runs the command and the argument
        cmnd->second->execute(swrod);
    }
}
//destructs all the dynamically allocated objects and commands
CommandPrompt::~CommandPrompt(){
    delete fileSystem;
    delete fileFactory;
    for(auto it = commandList.begin();it!=commandList.end();it++){
        delete it->second;
    }
}




