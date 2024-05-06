
#include "mockos/BasicDisplayVisitor.h"
#include "mockos/MetadataDisplayVisitor.h"


using namespace std;
int main(){

    ImageFile a = ImageFile("hi");
    vector <char> contents = a.read();
    contents = {'a','b','c'};
    a.write(contents);
    a.read();
    vector <char> contents1 = a.read();
    cout<<contents[FirstIndex]<<endl;


    TextFile textFile("FileName.txt");
    vector <char> c = {'h','e','l','l','o'};
    textFile.write(c);
    // Create an ImageFile with some content
    ImageFile imageFile("yes.img");
    vector<char> d = { 'X', ' ', ' ', 'X', ' ', 'X', 'X',' ', 'X', '3'};
    imageFile.write(d);
    // Create a BasicDisplayVisitor
    BasicDisplayVisitor visitor;
    // Use visitor to display the contents of both files
    textFile.accept(&visitor);
    imageFile.accept(&visitor);

    MetadataDisplayVisitor visitor1;
    textFile.accept(&visitor1);
    imageFile.accept(&visitor1);
    return 0;

}