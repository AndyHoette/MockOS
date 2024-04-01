# Studio 16

1. Andy, Andrew, Peter

2. In C++ an interface is just a class with all pure virtual methods. The interface can define member
variables and method but doesn't impliment the methods

3a. Since AbstractFile has only virtual functions we only really care about the interface and interface
inheritence is what we want.

3b. Without good reason to make a variable protected or public the variable should be made private
so at least for now the member variables will be private.

4. To test our textfile we created an instance wrote to it, printed it out, appened it, printed it out,
over wrote it, printed it out, printed out the name, and then printed out the size. All of these
tests worked as expected.

5. I used a pointer to an AbstractFile to interact with a textFile.

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
