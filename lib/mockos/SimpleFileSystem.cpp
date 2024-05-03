#include "mockos/SimpleFileSystem.h"
#include <iostream>
#include <memory>
#include "mockos/ImageFile.h"
#include "mockos/TextFile.h"
#include <string>
#include <set>
#include <map>

using namespace std;
int SimpleFileSystem::addFile(string n, AbstractFile * f){
    if(allFiles.count(n)!=0){
        return fileExists;
    }
    if(f == nullptr){
        return noFile;
    }
    pair<string, AbstractFile*> p;
    p.first = n;
    p.second = f;
    allFiles.insert(p);

    return fileSuccess;
};

int SimpleFileSystem::createFile(string n) {
    if (allFiles.count(n) != 0){
        return fileExists;
    }
    size_t pos = n.rfind(".");
    string ext = n.substr(pos+1);
    AbstractFile* filePointer = nullptr;
    if(pos==string::npos){
        return noExt;
    }
    if(ext == "txt"){
        filePointer = new TextFile(n);
    }
    else if(ext == "img"){
        filePointer = new ImageFile(n);
    }
    else{
        return noViableFile;
    }
    pair<string, AbstractFile*> p;
    p.first = n;
    p.second = filePointer;
    allFiles.insert(p);
    return SimpleFileSuccess;
}

AbstractFile * SimpleFileSystem::openFile(string n){
    if (allFiles.count(n) == 0){
        return nullptr;
    }
    AbstractFile* it  = allFiles[n];
    if(openFiles.find(it) != openFiles.end()){
        return nullptr;
    }
    openFiles.insert(allFiles[n]);
    return allFiles[n];
}

int SimpleFileSystem::closeFile(AbstractFile * f){
    if(openFiles.find(f) != openFiles.end()){
        openFiles.erase(f);
        return SimpleFileSuccess;
    }
    return noViableFile;
}

int SimpleFileSystem::deleteFile(string n) {
    auto it = allFiles.find(n);
    if (allFiles.count(n) == 0){
        return noFile;
    }
    auto it1 = allFiles[n];
    if(openFiles.find(it1) != openFiles.end()){
        return cantDeleteOpenFile;
    }
    delete it->second;
    allFiles.erase(it);
    return SimpleFileSuccess;
}

set<string> SimpleFileSystem::getFileNames() {
    set<string> ans;
    for(auto it = allFiles.begin(); it!=allFiles.end(); it++){
        ans.insert(it->first);
    }
    return ans;
}

set<AbstractFile *> SimpleFileSystem::getFiles() {
    set<AbstractFile*> ans;
    for(auto it = allFiles.begin(); it!=allFiles.end(); it++){
        ans.insert(it->second);
    }
    return ans;
}
