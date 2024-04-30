# Studio 20

2. We need to delete the file the pointer points to in order to avoid having a memory leak because we can only
access the file through the password proxy for security reasons, if we deleted the password proxy without deleting the
file we could lose any way to access the file.

4. We did a simple test by making a txt file, putting a password on it then writing, reading, and 
displaying it. The results were what we expected the display function printed out what we had written.

5. We forgot to include return statement in our PasswordProxy read method so it was always returns an
empty vector even if the password was valid.