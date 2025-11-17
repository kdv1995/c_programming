Example
Show the current position in a file:

FILE *fptr;
fptr = fopen("filename.txt", "a");

int position = ftell(fptr);
printf("%d", position);

fclose(fptr);
Definition and Usage
The ftell() function returns the value of position indicator. This is the position in the file where the next read or write operation will be done.

The ftell() function is defined in the <stdio.h> header file.

Syntax
ftell(FILE * fptr);
Parameter Values
Parameter	Description
fptr	Required. A file pointer, usually created by the fopen() function.
Technical Details
Returns:	An int value representing the current value of the position indicator.
