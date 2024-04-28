#include "mockos/TextFile.h"
#include "mockos/AbstractFileVisitor.h"
using namespace std;
TextFile::TextFile(const string& filename) : name(filename){}

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

vector <char> TextFile::read() {
    return contents;
}

void TextFile::accept(AbstractFileVisitor* visitor){
    visitor->visit_TextFile(this);
}