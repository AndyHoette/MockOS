#include "mockos/TouchCommand.h"

using namespace std;

TouchCommand::TouchCommand(AbstractFileSystem * newAFS, AbstractFileFactory * newAFF) : afs(newAFS), aff(newAFF){}

void TouchCommand::displayInfo() {
    cout << "touch creates a file, touch can be invoked with the command: touch <filename>" << endl;
}

int TouchCommand::execute(string arg) { //creates a file with a given name and makes it password protected if "-p"
    size_t idxOfFirstSpace = arg.find(' '); //if there is no arg after file then idxOfFirst Space is string::npos
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
    AbstractFile * newFile = aff->createFile(fileName);
    if(newFile==nullptr){
        return TouchCreateError;
    }
    if(!restOfArg.empty() && restOfArg!="-p"){
        return TouchAddError;
    }
    if(restOfArg.empty()){
        int addFileValue = afs->addFile(fileName, newFile);
        if(addFileValue!=fileSuccess){
            delete newFile; //if the file couldn't be added we need to delete it
            return TouchAddError;
        }
    }
    else{ //asks and sets the password
        string password;
        cout << "What is the password?" << endl;
        getline(cin, password);
        auto pp = new PasswordProxy(newFile, password);
        int addFileValue = afs->addFile(fileName, pp);
        if(addFileValue!=fileSuccess){
            delete pp; //if the file couldn't be added to the afs we need to delete it
            return TouchAddError;
        }
    }
    return commandSuccess;
}