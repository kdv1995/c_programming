Example
Write a character to a file:

FILE *fptr;

// Open a file in writing mode
fptr = fopen("filename.txt", "w");

// Write a character to the file
fputc('A', fptr);

fclose(fptr);
Definition and Usage
The fputc() function writes a single character to a file and moves the position indicator forward by one character.

The fputc() function is defined in the <stdio.h> header file.

Syntax
fputc(int c, FILE * fptr);
Parameter Values
Parameter	Description
c	Required. The ASCII value of a character. An actual character can also be used in this parameter.
fptr	Required. A file pointer, usually created by the fopen() function.
Technical Details
Returns:	An int value representing the ASCII value of the character, or the constant EOF if the character could not be written into the file.
