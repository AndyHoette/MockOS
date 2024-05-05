#include "mockos/DisplayCommand.h"

using namespace std;

DisplayCommand::DisplayCommand(AbstractFileSystem * newAFS): afs(newAFS) {}

void DisplayCommand::displayInfo() {
    cout << "display is supposed to be run with <filename> and an optional -d to make the out unformatted" << endl;
}
//Displays the contents of a file to the terminal
int DisplayCommand::execute(string arg) {
    size_t idxOfFirstSpace = arg.find(' ');
    string fileName;
    string restOfArg;
    if(idxOfFirstSpace==string::npos){
        fileName = arg;
        restOfArg = "";
    }
    else{
        fileName = arg.substr(0,idxOfFirstSpace);
        restOfArg = arg.substr(idxOfFirstSpace+1, arg.length()-idxOfFirstSpace);
    }
    if(!(restOfArg.empty() || restOfArg=="-d")){
        return DisplayCommandError;
    }
    AbstractFile * fileToDisplay = afs->openFile(fileName);
    if(fileToDisplay==nullptr){
        return DisplayCommandError;
    }
    if(restOfArg.empty()){//if user want's it formatted, runs accept on the file
        BasicDisplayVisitor v;
        fileToDisplay->accept(&v);
    }
    else{
        vector<char> vectorToPrint = fileToDisplay->read();//if not formatted, just prints out the vector
        for(auto it = vectorToPrint.begin(); it!=vectorToPrint.end(); it++){
            cout << *it;
        }
        cout<<'\n';
    }
    afs->closeFile(fileToDisplay);
    return DisplayCommandSuccess;
}