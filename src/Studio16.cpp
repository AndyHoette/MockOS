#include "mockos/TextFile.h"
using namespace std;
int main(){
    string testName = "test123";
    vector<char> vc = {'a', 'b', 'c'};
    TextFile txtFile = TextFile(testName);
    AbstractFile * f = &txtFile;
    f->write(vc);
    f->read();
    f->append(vc);
    f->read();
    f->write(vc);
    f->read();
    cout << f->getName() << endl;
    cout << f->getSize() << endl;
};