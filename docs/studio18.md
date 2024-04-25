# Studio 18

2. It wouldn't be difficult to change SimpleFileSystem to use different file type, but the code
it's very extendable because it has a lot of dependencies. It would easier to create an object that handles
this for us.

3. We think a new concrete file factory class should be made when we want to give the user different
file types. To introduce a new file type we would only have to add a new conditional statement at the end 
of our factory method. Yes, if two file systems have the same file types then we can use the same factory.
I think it would be ill-adviced to use the same factory if we used different file types because it would
inject dependencies else where in the code.

4. We created a few files and added them to the file system. We first opened the file using the openFile() 
function. We used the write function to write a txt file we created with a factory. We used the read function
which printed out what we had written in.

5. Once we include an SimpleFileFactory the simpleFileSystem no long depend on concrete types of files.
