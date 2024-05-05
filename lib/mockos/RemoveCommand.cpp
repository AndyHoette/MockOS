#include "mockos/RemoveCommand.h"

using namespace std;

RemoveCommand::RemoveCommand(AbstractFileSystem * newAFS) : afs(newAFS){}

int RemoveCommand::execute(string arg) {
    return afs->deleteFile(arg); //delets the file from afs
}

void RemoveCommand::displayInfo() {
    cout << "remove should be called with <filename> that you want to remove" << endl;
}