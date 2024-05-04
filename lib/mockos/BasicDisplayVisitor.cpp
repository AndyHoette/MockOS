#include "mockos/BasicDisplayVisitor.h"
#include <iostream>
using namespace std;

void BasicDisplayVisitor::visit_ImageFile(ImageFile* file){
    int s = file->getRowSize();
    vector<char> contents =file->read();
    for(int i = contents.size(); i>0; i-=s){
        for(int j = 0; j<s; j++){
            cout << contents[i-s+j];
        }
        cout << endl;
    }
}

void BasicDisplayVisitor::visit_TextFile(TextFile *file) {
    vector<char> contents = file->read();
    for(int i = 0; i<contents.size(); i++){
        cout << contents[i];
    }
    cout << endl;
}
