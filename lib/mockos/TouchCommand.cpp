#include "mockos/TouchCommand.h"

using namespace std;

TouchCommand::TouchCommand(AbstractFileSystem * newAFS, AbstractFileFactory * newAFF) : afs(newAFS), aff(newAFF){}

void TouchCommand::displayInfo() {
    cout << "touch creates a file, touch can be invoked with the command: touch <filename>" << endl;
}

int TouchCommand::execute(string fileName) {
    AbstractFile * newFile = aff->createFile(fileName);
    if(newFile==nullptr){
        return TouchCreateError;
    }
    int addFileValue = afs->addFile(fileName, newFile);
    if(addFileValue!=fileSuccess){
        delete newFile;
        return TouchAddError;
    }
    return commandSuccess;
}