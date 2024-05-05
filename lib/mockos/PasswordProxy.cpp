#include "mockos/PasswordProxy.h"
using namespace std;


PasswordProxy::PasswordProxy(AbstractFile *f, string& pw): protectedFile(f), password(pw){}

PasswordProxy::~PasswordProxy() {
    delete protectedFile;
}

string PasswordProxy::passwordPrompt() {
    string passwordGuess;
    cout << "Enter a Password: " << endl;
    cin >> passwordGuess;
    return passwordGuess;
}

bool PasswordProxy::passwordMatch(string guess) {
    return guess==password;
}

vector<char> PasswordProxy::read() {
    if(passwordMatch(passwordPrompt())){
        return protectedFile->read();
    }
    vector<char> n = {};
    return n;
}

int PasswordProxy::write(vector<char> newContents) {
    if(passwordMatch(passwordPrompt())){
        return protectedFile->write(newContents);
    }
    return noPassword;
}

int PasswordProxy::append(vector<char> newContents) {
    if(passwordMatch(passwordPrompt())){
        return protectedFile->append(newContents);
    }
    return noPassword;
}

uint PasswordProxy::getSize(){
    return protectedFile->getSize();
}

string PasswordProxy::getName() {
    return protectedFile->getName();
}

void PasswordProxy::accept(AbstractFileVisitor *vis ) {
    if(passwordMatch(passwordPrompt())){
        protectedFile->accept(vis);
    }
}

AbstractFile *PasswordProxy::clone(string newName) {
    AbstractFile * newProtectedFile = protectedFile->clone(newName);
    return new PasswordProxy(newProtectedFile, this->password);
}

bool PasswordProxy::hasPermissions() {
    return protectedFile->hasPermissions();
}

