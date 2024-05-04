#include "mockos/addPermissionCommand.h"

using namespace std;

void addPermissionCommand::displayInfo() {
    cout << "This command is to be run without an argument to change whether the file is readOnly" << endl;
}

int addPermissionCommand::execute(string arg) {
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
    if(!restOfArg.empty()){
        return failure;
    }
    AbstractFile * myFile = afs->openFile(fileName);
    if(myFile==nullptr){
        return failure;
    }
    if(myFile->hasPermissions()){
        myFile->changePermissions();
    }
    else{
        afs->deleteFile(myFile->getName());
        AbstractFile * filePointer = new PermissionProxy(myFile);
        afs->addFile(myFile->getName(),filePointer);
    }
    return success;
}