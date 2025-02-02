#include "mockos/addPermissionCommand.h"

using namespace std;
//displays the information
void addPermissionCommand::displayInfo() {
    cout << "This command is to be run without an argument to change whether the file is readOnly" << endl;
}
//either creates a permission proxy or changes the permission in the permission proxy
int addPermissionCommand::execute(string arg) {
    AbstractFile * myFile = afs->openFile(arg);
    if(myFile==nullptr){
        return fail;
    }
    if(myFile->hasPermissions()){//changes the permmisison in the permission proxy
        myFile->changePermissions();
        afs->closeFile(myFile);
    }
    else{//creates permission proxy
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

addPermissionCommand::addPermissionCommand(AbstractFileSystem * newAfs) : afs(newAfs){}//creates the persmission command