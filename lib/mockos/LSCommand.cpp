#include "mockos/LSCommand.h"

using namespace std;

LSCommand::LSCommand(AbstractFileSystem * newAFS) : afs(newAFS){}

void LSCommand::displayInfo() {
    cout << "ls should be run with no arguments or a -m to show meta data" << endl;
}
//prints out all the files in the file system for the user to see
int LSCommand::execute(string argumentation) {
    if(argumentation.empty()) {
        set<string> names = afs->getFileNames();
        bool newLine = false;
        for(auto it = names.begin(); it!=names.end(); it++){
            cout << *it << setw(20);
            if(newLine){
                cout << endl;
                cout << setw(0); //if the there is no -m then we print out two per line
            }
            newLine=!newLine;
        }
    }
    else if(argumentation=="-m"){ //if there is -m flag then we use a metaDataVisitor on all of files
        MetadataDisplayVisitor v;
        set<string> names = afs->getFileNames();
        for(auto it = names.begin(); it!=names.end(); it++){
            AbstractFile * fileToVisit = afs->openFile(*it);
            fileToVisit->accept(&v);
            afs->closeFile(fileToVisit);
        }
    }
    cout<<endl;
    return 0;
}