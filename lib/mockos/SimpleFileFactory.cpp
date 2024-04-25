#include "mockos/SimpleFileFactory.h"

using namespace std;
AbstractFile *SimpleFileFactory::createFile(string n) {
    size_t pos = n.rfind(".");
    if(pos == string::npos){
        return nullptr;
    }
    string ext = n.substr(pos+1);
    AbstractFile* filePointer = nullptr;
    if(ext == "txt"){
        filePointer = new TextFile(n);
    }
    else if(ext == "img"){
        filePointer = new ImageFile(n);
    }
    return filePointer;
}