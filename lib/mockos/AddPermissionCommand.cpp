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
        return fail;
    }
    AbstractFile * myFile = afs->openFile(fileName);
    if(myFile==nullptr){
        return fail;
    }
    if(myFile->hasPermissions()){
        myFile->changePermissions();
    }
    else{
        afs->closeFile(myFile);
        string name = myFile->getName();
        name = name.substr(0,name.find('.'));
        AbstractFile * cFile = myFile->clone(name);
        afs->deleteFile(myFile->getName());
        AbstractFile * filePointer = new PermissionProxy(cFile);
        afs->addFile(cFile->getName(),filePointer);
    }
    return success;
}

addPermissionCommand::addPermissionCommand(AbstractFileSystem * newAfs) : afs(newAfs){}