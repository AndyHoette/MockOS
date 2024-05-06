#include"mockos/SimpleFileSystem.h"
#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"

using namespace std;

int main(){
    /*Create a SimpleFileSystem object in main, create a few files and add them to the file
system via the addFile method. Create a few files via the createFile method as well. Try
opening, writing, reading, and deleting files to ensure things are working properly.*/
    AbstractFileSystem * sfs = new SimpleFileSystem();
    AbstractFile * file1 = new TextFile("file1");
    sfs->addFile("file1.txt", file1);
    sfs->createFile("file2.txt");
    AbstractFile * file2 = sfs->openFile("file2.txt");
    vector<char> v = {'h','i'};
    file2->write(v);
    vector<char> file2read = file2->read();
    for(char i: file2read){
        cout << i;
    }
    cout << endl;
    sfs->closeFile(file2);
    sfs->deleteFile("file2.txt");
    delete sfs;
}
