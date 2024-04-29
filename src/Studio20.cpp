#include "mockos/PasswordProxy.h"
#include "mockos/TextFile.h"
#include "mockos/BasicDisplayVisitor.h"

using namespace std;

int main(){
    string fileName = "newFileNameForUs";
    AbstractFile* realfile = new TextFile(fileName);
    string password = "r4A3dg";
    PasswordProxy* pp = new PasswordProxy(realfile, password);
    vector<char> newContentsYippie = {'a','n','d','y'};
    pp->write(newContentsYippie);
    pp->read();
    BasicDisplayVisitor visitor1;
    pp->accept(&visitor1);
    return 0;
}