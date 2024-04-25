#include "mockos/SimpleFileSystem.h"
#include "mockos/SimpleFileFactory.h"
using namespace std;


int main() {
    AbstractFileSystem *afs = new SimpleFileSystem(); //afs is a file system
    AbstractFileFactory *aff = new SimpleFileFactory(); //aff is a factory

    AbstractFile *af = aff->createFile("hi.txt"); //use the factory to create a txt file
    AbstractFile *af2 = aff->createFile("bye.img"); //use the factory to create a img file
    int add1 = afs->addFile("hi", af);
    int add2 = afs->addFile("bye", af2);
    AbstractFile *fileWeWant = afs->openFile("hi"); //fileWeWant should now point to (*af)
    vector<char> c1 = {'c', 'f', 'd'}; //creates a vector to write to
    int write1 = fileWeWant->write(c1); //writes c1 in fileWeWant's contents
    fileWeWant->read(); //read the fileWeWant should print "cfd"
    return 0; //return 0
}