#include "mockos/PermissionProxy.h"

using namespace std;

string PermissionProxy::getName() {
    return myFile->getName();
}

AbstractFile *PermissionProxy::clone(string newName) {
    AbstractFile * newPermissionFile = myFile->clone(newName);
    return new PermissionProxy(newPermissionFile, this->readOnly);
}

vector<char> PermissionProxy::read() {
    return myFile->read();
}

int PermissionProxy::write(std::vector<char> v) {
    if(readOnly){
        return operationNotSupported;
    }
    return myFile->write(v);
}

int PermissionProxy::append(std::vector<char> v) {
    if(readOnly){
        return operationNotSupported;
    }
    return myFile->append(v);
}

uint PermissionProxy::getSize() {
    return myFile->getSize();
}

void PermissionProxy::accept(AbstractFileVisitor *vis) {
    myFile->accept(vis);
}

PermissionProxy::PermissionProxy(AbstractFile *f, bool &rO) : myFile(f),readOnly(rO){}

PermissionProxy::PermissionProxy(AbstractFile *f) : myFile(f),readOnly(true){}

PermissionProxy::~PermissionProxy() {
    delete myFile;
}

bool PermissionProxy::hasPermissions() {
    return true;
}

void PermissionProxy::changePermissions() {
    readOnly = !readOnly;
}