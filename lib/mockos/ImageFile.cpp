#include "mockos/ImageFile.h"
using namespace std;
ImageFile::ImageFile(string& n) : name(n), size('0'){}

uint ImageFile::getSize(){
    return contents.size() - '0';
}

string ImageFile::getName(){
    return name;
}

int ImageFile::write(std::vector<char> c) {
    int size = c[c.size()-1]-'0';
    c.pop_back();
    contents = c;
    return size;
}

int ImageFile::append(std::vector<char> c){
    return operationNotSupported;
}

void ImageFile::read() {
    int s = getSize();
    for(int i = this->contents.size(); i>0; i-=s){
        for(int j = 0; j<s; j++){
            cout << contents[i-s+j];
        }
        cout << endl;
    }
}