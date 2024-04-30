#include "mockos/RemoveCommand.h"

using namespace std;

RemoveCommand::RemoveCommand(AbstractFileSystem * newAFS, AbstractFileFactory * newAFF) : afs(newAFS), aff(newAFF){}

int RemoveCommand::execute(string arg) {
    return afs->deleteFile(arg);
}