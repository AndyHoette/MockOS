#include "mockos/TextFile.h"
using namespace std;

TextFile::TextFile(string& n) : name(n){}
TextFile::TextFile(const std::string& filename) : name(filename){}

uint TextFile::getSize() {
    return contents.size();
}

string TextFile::getName() {
    return name;
}

int TextFile::write(vector<char> c) {
    contents = c;
    return success;
}

int TextFile::append(vector<char> c) {
    for(int i = 0; i<c.size(); i++){
        contents.push_back(c[i]);
    }
    return success;
}

void TextFile::read() {
    for(int i = 0; i<contents.size(); i++){
        cout << contents[i];
    }
    cout << endl;
}