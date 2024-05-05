#include "mockos/PermissionProxy.h"

using namespace std;

string PermissionProxy::getName() { //returns the name of the file
    return myFile->getName();
}

AbstractFile *PermissionProxy::clone(string newName) {
    AbstractFile * newPermissionFile = myFile->clone(newName); //clones proxy with the same readOnly value
    return new PermissionProxy(newPermissionFile, this->readOnly);
}

vector<char> PermissionProxy::read() { //simply reads
    return myFile->read();
}

int PermissionProxy::write(std::vector<char> v) { //writes if the proxy isn't read only
    if(readOnly){
        cout <<"operation not supported" <<endl;
        return operationNotSupported;
    }
    return myFile->write(v);
}

int PermissionProxy::append(std::vector<char> v) { //appends if the proxy isn't read only
    if(readOnly){
        return operationNotSupported;
    }
    return myFile->append(v);
}

uint PermissionProxy::getSize() { //returns size
    return myFile->getSize();
}

void PermissionProxy::accept(AbstractFileVisitor *vis) { //just runs accept on myFile
    myFile->accept(vis);
}

PermissionProxy::PermissionProxy(AbstractFile *f, bool &rO) : myFile(f),readOnly(rO){} //if passed 2 args

PermissionProxy::PermissionProxy(AbstractFile *f) : myFile(f),readOnly(true){} //sets readOnly to true by default

PermissionProxy::~PermissionProxy() { //makes sure to delte myFile
    delete myFile;
}

bool PermissionProxy::hasPermissions() { //returns true
    return true;
}

void PermissionProxy::changePermissions() { //changes the read Only
    readOnly = !readOnly;
}
