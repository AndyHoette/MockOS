# Studio 20

1. Andy Hoette, Andrew Hyde, Peter Adams-Agresti

2. We need to delete the file the pointer points to in order to avoid having a memory leak because we can only
access the file through the password proxy for security reasons, if we deleted the password proxy without deleting the
file we could lose any way to access the file.

4. We did a simple test by making a txt file, putting a password on it then writing, reading, and 
displaying it. The results were what we expected the display function printed out what we had written.

5. We forgot to include a return statement in our PasswordProxy read method, so it was always returned an
empty vector even if the password was valid. To fix this we added the return statement. 