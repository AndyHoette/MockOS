#include "mockos/TouchCommand.h"

using namespace std;

TouchCommand::TouchCommand(AbstractFileSystem * newAFS, AbstractFileFactory * newAFF) : afs(newAFS), aff(newAFF){}

void TouchCommand::displayInfo() {
    cout << "touch creates a file, touch can be invoked with the command: touch <filename>" << endl;
}

int TouchCommand::execute(string arg) {
    size_t idxOfFirstSpace = arg.find(' ');
    string fileName = arg.substr(0,idxOfFirstSpace);
    string restOfArg = arg.substr(idxOfFirstSpace+1, arg.length()-idxOfFirstSpace);
    AbstractFile * newFile = aff->createFile(fileName);
    if(newFile==nullptr){
        return TouchCreateError;
    }
    if(!restOfArg.empty() || restOfArg!="-p"){
        return TouchAddError;
    }
    if(restOfArg.empty()){
        int addFileValue = afs->addFile(fileName, newFile);
        if(addFileValue!=fileSuccess){
            delete newFile;
            return TouchAddError;
        }
    }
    else{
        string password;
        cout << "What is the password?" << endl;
        getline(cin, password);
        auto pp = new PasswordProxy(newFile, password);
        int addFileValue = afs->addFile(fileName, pp);
        if(addFileValue!=fileSuccess){
            delete pp;
            return TouchAddError;
        }
    }
    return commandSuccess;
}