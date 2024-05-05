# Lab 5
Workers: Andrew Hyde, Andy Hoette, Peter Adams-Agresti
We all worked on all parts of the lab together on one computer. This was easy for us to do 
as it gave us a good way to work together and bounce ideas off eachother. 

Error Enums and when they show up:
Our error messages do not show up in the main method as it either works or is terminated. The error messages we do have 
are good for debugging and internal use but not applicable to the user 

ERRORS:

We had substring issues when trying to implement the copy command. We tried to add the file extension
in the command file instead of in the specific txt or img files. This caused the copy to act as though
there were multiple extensions. We simply allowed the instances of the abstract file class to deal with 
their own extensions

When we were printing out an image file, we were using the getSize() function that we had created to get 
the size of the array, when in reality, we should have been accessing the last element in the vector of chars
to get the size. This was printing an out of bounds error. We fixed it by using the last element of the vector of chars

We encountered an indexing issue when trying to parse an argument within the command execute method. We were getting the entire input
instead of just the second half of the input. We fixed it by creating an if else statment that would make the second half of 
the arg blank and just run the first part. 

We had an issue with the command prompt when passing in multiple arguemnts. We tried to use the string stream.str method 
but this took the entire argument and not just after the command. We fixed this by changing the second word to be equal to a 
substring starting at the index of the first space +1. 

We had an issue with copying the contents of an imageFile. The contents of the image file did not have the size char on the
end of the vector so when we tried to write to the new copy with the contents vector it didn't have the size. 
We created a new vector and added the size char on the end so when we wrote to it the program had the correct input and could
create the copy. 

MEMORY:
In our program we dynamically allocate files, factories, commandPrompts, commands, parsingStrategies, and fileSystems.
Since they are all contained with in a command prompt through some means we can use can call the destructors within
the commandPrompt destructor. The Command prompt makes sure to delete factories, commands, fileSystems. The macro
command makes sure that the parsingStrategy and sub-commands are deleted. The fileSystem takes care of deleting the
files within it.

TEST CASES:

touch file.txt
ls
file.txt
touch file
ls
file.txt
touch file.img
ls
file.img     file.txt
touch file1.txt -p
What is the password?
123
ls
file.img     file.txt
file1.txt

This shows that we can create files with the touch command including .txt, .img, and password protected files.
The command also can handle bad inputs and properly deals with them

cat file.txt
Enter data you would like to write
12345
:wq
ds file.txt
Enter data you would like to write
12345
cat file.txt
678
:q
ds file.txt
12345
cat file.txt -a
12345
Enter data you would like to append
6789
:wq
ds file.txt
123456789
cat file.img
Enter data you would like to write
X__X__X__3 (the underscores represent spaces)
:wq
ds file.img
X__
X__
X__
ds file.img -d
X__X__X__

This shows that cat and ds work on standard files including txt and img files

rm file.txt
ls
file.img file1.txt
cat file.txt
File Not Found
rn file.img newFile
ls
file1.txt newFile.img
cp newFile.img newNewFile.img
ls
file1.txt newFile.img
newNewFile.img
ds newNewFile.img
X__
X__
X__

This shows that remove, copy and rename work properly for our file system including a copying of the contents array

cds newFile.img
Enter data you would like to write to the file.
X X X X X3
:wq
X _ X
_ X _
X _ X
touch file4.txt
cat file4.txt
12345
:wq
cds file4.txt -a
12345
Enter the data would like to append to the file.
678
:wq
12345678
q

Process finished with exit code 0

This shows that cds works with extensions is allowed and that q to quit works.

help
\[lists all commands in the command prompt\]
help cp
Copy should be run with <fileYouWantCopied> <newName>

This help and then command works for all of our basic commands and provides the user info on how to run the command
Macros display the specific help messages of each command within each macro

Extra Credit:

For our extra credit we decided to be able to toggle files to be readOnly. To do this we implimented the proxy pattern
similar to the password Proxy. When per <fileName> is run the system first checks if the file we passed already has
a permission proxy or is a password proxy for a permission proxy. If the file already has a permission proxy then we
simply toggle the readOnly boolean to be in the other state. If the file doesn't have a permission proxy we create
a permission proxy with the file passed, remove the file from the fileSystem, and add the permission proxy to the file
System with the same name as the file. If you try to write or append to a file with a permission proxy with a
readOnly value of true then the operation will not work. All other operation work the same


