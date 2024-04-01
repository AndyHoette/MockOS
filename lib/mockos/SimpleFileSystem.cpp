#include "mockos/SimpleFileSystem.h"
using namespace std;
int SimpleFileSystem::addFile(string n, AbstractFile * f){
    if(m.count(n)!=0){
        return fileExists;
    }
    if(f == nullptr){
        return noFile;
    }
    pair<string, AbstractFile*> p;
    p.first = n;
    p.second = f;
    m.insert(p);
    return SimpleFileSuccess;
};

