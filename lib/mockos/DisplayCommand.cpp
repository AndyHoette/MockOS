#include "mockos/DisplayCommand.h"

using namespace std;

DisplayCommand::DisplayCommand(AbstractFileSystem * newAFS): afs(newAFS) {}

void DisplayCommand::displayInfo() {
    cout << "display is supposed to be run with <filename> and an optional -d to make the out unformatted" << endl;
}

int DisplayCommand::execute(string arg) {
    size_t idxOfFirstSpace = arg.find(' ');
    string fileName = arg.substr(0,idxOfFirstSpace);
    string restOfArg = arg.substr(idxOfFirstSpace+1, arg.length()-idxOfFirstSpace);
    if(!(restOfArg.empty() || restOfArg=="-d")){
        return DisplayCommandError;
    }
    AbstractFile * fileToDisplay = afs->openFile(fileName);
    if(fileToDisplay==nullptr){
        return DisplayCommandError;
    }
    if(restOfArg.empty()){
        BasicDisplayVisitor v;
        fileToDisplay->accept(&v);
    }
    else{
        vector<char> vectorToPrint = fileToDisplay->read();
        for(auto it = vectorToPrint.begin(); it!=vectorToPrint.end(); it++){
            cout << *it;
        }
    }
    return DisplayCommandSuccess;
}