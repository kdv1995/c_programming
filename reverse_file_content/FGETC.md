Example
Read a character from a file:

FILE *fptr;

// Open a file in read mode
fptr = fopen("filename.txt", "r");

// Read a single character from the file
char c = fgetc(fptr);

// Print the character
printf("%c", c);

// Close the file
fclose(fptr);
Definition and Usage
The fgetc() function returns the ASCII value of the character at the current position in the file and then moves the position indicator to the next character.

The fgetc() function is defined in the <stdio.h> header file.

Syntax
fgetc(FILE * fptr);
Parameter Values
Parameter	Description
fptr	Required. A file pointer, usually created by the fopen() function.
Technical Details
Returns:	An int value representing the ASCII value of the character at the current position in the file, or the constant EOF if the end of the file has been reached or an error occurred.
