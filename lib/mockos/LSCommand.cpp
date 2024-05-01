#include "mockos/LSCommand.h"

using namespace std;

LSCommand::LSCommand(AbstractFileSystem * newAFS) : afs(newAFS){}

void LSCommand::displayInfo() {
    cout << "ls should be run with no arguments or a -m to show meta data" << endl;
}

int LSCommand::execute(string argumentation) {
    cout << setw(20);
    if(argumentation.empty()) {
        set<string> names = afs->getFileNames();
        bool newLine = false;
        for(auto it = names.begin(); it!=names.end(); it++){
            cout << *it;
            if(newLine){
                cout << endl;
            }
            newLine=!newLine;
        }
    }
    else if(argumentation=="-m"){
        MetadataDisplayVisitor v;
        set<AbstractFile*> files = afs->getFiles();
        for(auto it = files.begin(); it!=files.end(); it++){
            (*it)->accept(&v);
        }
    }
    return 0;
}