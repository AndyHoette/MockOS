#include "mockos/CopyCommand.h"

using namespace std;

CopyCommand::CopyCommand(AbstractFileSystem * newAFS): afs(newAFS) {}

void CopyCommand::displayInfo() {
    cout <<"Copy should be run with <fileYouWantCopied> <newName>" << endl;
}

int CopyCommand::execute(string arg) {
    size_t idxOfFirstSpace = arg.find(' ');
    size_t idxOfFirstDot = arg.find('.');
    string fileExtension = arg.substr(idxOfFirstDot,idxOfFirstSpace);
    string fileName = arg.substr(0,idxOfFirstSpace);
    string newName = arg.substr(idxOfFirstSpace+1, arg.length()-idxOfFirstSpace);
    AbstractFile * fileToCopy = afs->openFile(fileName);
    if(fileToCopy== nullptr){
        return CopyCommandError;
    }
    AbstractFile * copiedFile = fileToCopy->clone(newName);
    int addFileValue = afs->addFile(newName+fileExtension, copiedFile);
    if(addFileValue!=AbstractFileSuccess){
        delete copiedFile;
        cout << "File Copy Failed" << endl;
        afs->closeFile(fileToCopy);
        return CopyCommandError;
    }
    afs->closeFile(fileToCopy);
    return CopyCommandSuccess;
}