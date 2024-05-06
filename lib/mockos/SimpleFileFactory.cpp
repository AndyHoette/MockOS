#include "mockos/SimpleFileFactory.h"

using namespace std;
AbstractFile *SimpleFileFactory::createFile(string n) {
    size_t pos = n.rfind(".");
    if(pos == string::npos){ //if there isn't an extension it isn't a valid file
        return nullptr;
    }
    string ext = n.substr(pos+1);
    AbstractFile* filePointer = nullptr;
    if(ext == "txt"){ //if the file ends in txt then make a textFile
        filePointer = new TextFile(n);
    }
    else if(ext == "img"){ //if it is .img make an image file
        filePointer = new ImageFile(n);
    }
    return filePointer;
}