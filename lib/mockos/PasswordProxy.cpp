#include "mockos/PasswordProxy.h"
using namespace std;


PasswordProxy::PasswordProxy(AbstractFile *f, string& pw): protectedFile(f), password(pw){} //basic constructor

PasswordProxy::~PasswordProxy() { //we have to delete the file when we delete the proxy
    delete protectedFile;
}

string PasswordProxy::passwordPrompt() { //this prompts the user and returns their guess
    string passwordGuess;
    cout << "Enter a Password: " << endl;
    cin >> passwordGuess;
    flush(cout);
    return passwordGuess;
}

bool PasswordProxy::passwordMatch(string guess) { //returns a bool indicating if the user guessed right
    return guess==password;
}

vector<char> PasswordProxy::read() { //only reads if the password is passed otherwise pass an empty vector
    if(passwordMatch(passwordPrompt())){
        return protectedFile->read();
    }
    vector<char> n = {};
    return n;
}

int PasswordProxy::write(vector<char> newContents) { //only writes if the password is correct
    if(passwordMatch(passwordPrompt())){
        return protectedFile->write(newContents);
    }
    return noPassword;
}

int PasswordProxy::append(vector<char> newContents) { //only appends if the password is correct
    if(passwordMatch(passwordPrompt())){
        return protectedFile->append(newContents);
    }
    return noPassword;
}

uint PasswordProxy::getSize(){ //no password need for get size
    return protectedFile->getSize();
}

string PasswordProxy::getName() { //or for get name
    return protectedFile->getName();
}

void PasswordProxy::accept(AbstractFileVisitor *vis ) { //the accept  just runs accept on the file if the password
    if(passwordMatch(passwordPrompt())){
        protectedFile->accept(vis);
    }
}

AbstractFile *PasswordProxy::clone(string newName) { //creates a clone with the same password
    AbstractFile * newProtectedFile = protectedFile->clone(newName);
    return new PasswordProxy(newProtectedFile, this->password);
}

bool PasswordProxy::hasPermissions() { //returns whether its protected file is a permission proxy
    return protectedFile->hasPermissions();
}

