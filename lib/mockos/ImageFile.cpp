#include "mockos/ImageFile.h"

#include <utility>
using namespace std;
ImageFile::ImageFile(string filename) : name(filename),fileSize('0') {}
uint ImageFile::getSize(){
    return static_cast<size_t>(contents.size());;
}
string ImageFile::getName(){
    return name;
}

int ImageFile::write(vector<char> c){
    if (!c.empty()) {
        char potentialSize = c.back();
        if (isdigit(potentialSize)) {
            int n = potentialSize - '0';  // Convert char to int
            if (n * n == c.size() - 1) {  // Check size consistency
                fileSize = potentialSize;
                contents = std::vector<char>(c.begin(), c.end() - 1);
                return 0;  // Success
            }
        }
    }
    contents.clear();
    fileSize = '0';
    return 1;  // Error
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