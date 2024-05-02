#include "mockos/CopyCommand.h"

using namespace std;

CopyCommand::CopyCommand(AbstractFileSystem * newAFS): afs(newAFS) {}

void CopyCommand::displayInfo() {
    cout <<"Copy should be run with <fileYouWantCopied> <newName>" << endl;
}

int CopyCommand::execute(string arg) {
    size_t idxOfFirstSpace = arg.find(' ');
    string fileName = arg.substr(0,idxOfFirstSpace); //copy.txt
    string newName = arg.substr(idxOfFirstSpace+1, arg.length()-idxOfFirstSpace); //copy
    AbstractFile * fileToCopy = afs->openFile(fileName); //open copy.txt
    if(fileToCopy== nullptr){
        return CopyCommandError;
    }
    AbstractFile * copiedFile = fileToCopy->clone(newName); //creates a file with name copy.txt
    int addFileValue = afs->addFile(copiedFile->getName(), copiedFile);
    if(addFileValue!=AbstractFileSuccess){
        delete copiedFile;
        cout << "File Copy Failed" << endl;
        afs->closeFile(fileToCopy);
        return CopyCommandError;
    }
    afs->closeFile(fileToCopy);
    return CopyCommandSuccess;
}