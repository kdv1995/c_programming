Example
Write a string into a file:

FILE *fptr;

// Open a file in writing mode
fptr = fopen("filename.txt", "w");

// Write a string into the file
fputs("Hello World!", fptr);

fclose(fptr);
Definition and Usage
The fputs() function writes a string into a file.

The fputs() function is defined in the <stdio.h> header file.

Syntax
fputs(const char * str, FILE * fptr);
Parameter Values
Parameter	Description
str	Required. A char array containing the string to be written.
fptr	Required. A file pointer, usually created by the fopen() function.
Technical Details
Returns:	An int value that is not negative if the function was successful. It returns the constant EOF if an error occurred.
