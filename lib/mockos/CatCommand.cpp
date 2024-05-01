#include "mockos/CatCommand.h"

using namespace std;

CatCommand::CatCommand(AbstractFileSystem * newAFS): afs(newAFS) {}

void CatCommand::displayInfo() {
    cout << "cat is supposed to be run with <filename> and optional with a -a at the end to append instead of writing" << endl;
}

int CatCommand::execute(string arg) {
    size_t idxOfFirstSpace = arg.find(' '); //if there is no arg after file then idxOfFirst Space is string::npos
    string fileName;
    string restOfArg;
    if(idxOfFirstSpace==string::npos){
        fileName = arg;
        restOfArg = "";
    }
    else{
        fileName = arg.substr(0,idxOfFirstSpace);
        restOfArg = arg.substr(idxOfFirstSpace+1, arg.length()-idxOfFirstSpace);
    }
    if(!(restOfArg.empty() || restOfArg=="-a")){
        return CatCommandError;
    }
    AbstractFile * fileToCat = afs->openFile(fileName);
    if(fileToCat==nullptr){
        return CatCommandError;
    }
    if(restOfArg.empty()){
        cout << fileName << endl;
        cout << "Enter data you would like to write to the file. Enter :wq to save the file and exit and :q to exit without saving" << endl;
    }
    else{
        cout << fileName << endl;
        BasicDisplayVisitor v;
        fileToCat->accept(&v);
        cout << "Enter data you would like to append to the file. Enter :wq to save the file and exit and :q to exit without saving" << endl;
    }
    vector<char> vectorToCat;
    while(1) {
        string curr;
        getline(cin, curr);
        if(curr == ":q"){
            afs->closeFile(fileToCat);
            return noSave;
        }
        else if(curr == ":wq"){
            break;
        }
        else{
            //copy contents to vectorToCat
            if(!vectorToCat.empty()){
                vectorToCat.push_back('\n');
            }
            copy(curr.begin(), curr.end(), std::back_inserter(vectorToCat));
        }
    }
    if(restOfArg.empty()){
        fileToCat->write(vectorToCat);
    }
    else{
        vector<char> newLineV = {'\n'};
        fileToCat->append(newLineV);
        fileToCat->append(vectorToCat);
    }
    afs->closeFile(fileToCat);
    return CatCommandSuccess;
}