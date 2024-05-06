#include "mockos/PasswordProxy.h"
#include "mockos/TextFile.h"
#include "mockos/BasicDisplayVisitor.h"

using namespace std;

int main(){
    string fileName = "newFileNameForUs";
    AbstractFile* realfile = new TextFile(fileName); //cretes a file
    string password = "r4A3dg";
    PasswordProxy* pp = new PasswordProxy(realfile, password); //then creates a password proxy for this
    vector<char> newContentsYippie = {'a','n','d','y'};
    pp->write(newContentsYippie); //waits for the user to input the password
    pp->read(); //also waits for user input for the password
    BasicDisplayVisitor visitor1;
    pp->accept(&visitor1); //prints it out
    return 0;
}