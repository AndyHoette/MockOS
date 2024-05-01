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

int ImageFile::write(vector<char> c){{
    if (c.empty()) { // Early return if `c` is empty
        contents.clear();
        fileSize = '0';
        return noContents; // Error due to no contents
    }
        for(auto i = c.begin(); i<c.end()-1; i++){ //loop through the elements besides the last
            if((*i)!='X' && (*i)!=' '){ //image is only X and ' ' so if its not clear contents and return error
                fileSize = '0';
                contents.clear();
                return wrongContents;
            }
        }
        //we can say that c is non-empty and only has X and ' '
        char potentialSize = c.back(); //the last char in c is the size inidcator
        if (isdigit(potentialSize)) { //if its a digit
            int n = potentialSize - '0';  // Convert char to int
            if (n * n == c.size() - 1) {  //c should be an nxn image
                fileSize = potentialSize; //cement the changes
                contents = std::vector<char>(c.begin(), c.end() - 1);
                return AbstractFileSuccess;  // Success
            }
        }
    }
    contents.clear(); //if c was empty
    fileSize = '0'; //set file size to 0
    return noContents;  // Error
}

int ImageFile::append(std::vector<char> c){
    return operationNotSupported;
}

vector<char> ImageFile::read() {
    return contents;
}

void ImageFile::accept(AbstractFileVisitor* visitor) {
    visitor->visit_ImageFile(this);
}

AbstractFile *ImageFile::clone(string newName) {
    AbstractFile* newFile = new ImageFile(newName);
    newFile->write(this->contents);
    return newFile;
}